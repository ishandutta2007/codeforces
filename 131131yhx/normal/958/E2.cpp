#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long

typedef long long ll;

using namespace std;

struct node {
    int a, b;
    node() {}
    node(int _1, int _2) {
        a = _1;
        b = _2;
    }
    bool operator < (const node& X) const {
        return a > X.a;
    }
};
priority_queue <node> Q;

int Nxt[500010], Pre[500010], V[500010], K, n;

bool invalid[500010];

#undef int
int main() {
#define int long long
    scanf("%lld%lld", &K, &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &V[i]);
    sort(V + 1, V + n + 1);
    for(int i = 1; i < n; i++) V[i] = V[i + 1] - V[i];
    V[n] = 0;
    n--;
    V[0] = 1e18, V[n + 1] = 1e18;
    for(int i = 0; i <= n; i++) Nxt[i] = i + 1;
    for(int i = n + 1; i > 0; i--) Pre[i] = i - 1;
    for(int i = 1; i <= n; i++) Q.push(node(V[i], i));
    int ans = 0;
    while(K--) {
        node tmp = Q.top();
        while(invalid[tmp.b]) Q.pop(), tmp = Q.top();
        Q.pop();
        ans += tmp.a;
        int p = Pre[tmp.b], s = Nxt[tmp.b];
        V[tmp.b] = V[p] + V[s] - V[tmp.b];
        invalid[p] = 1;
        invalid[s] = 1;
        Pre[tmp.b] = Pre[p];
        Nxt[tmp.b] = Nxt[s];
        Nxt[Pre[tmp.b]] = tmp.b;
        Pre[Nxt[tmp.b]] = tmp.b;
        Q.push(node(V[tmp.b], tmp.b));
    }
    printf("%lld\n", ans);
}