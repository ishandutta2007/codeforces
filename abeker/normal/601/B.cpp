#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N, Q;
int a[MAXN];

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

ll get(pii p) {
    return (ll)p.first * p.second;
}

ll calc(const vector <int> &V) {
    stack <pii> S;
    S.push(pii(INF, -1));
    ll sum = 0, sol = 0;
    for (int i = 0; i < V.size(); i++) {
        int cnt = 1;
        for (; V[i] > S.top().first; S.pop()) {
            sum -= get(S.top());
            cnt += S.top().second;
        }
        pii tmp(V[i], cnt);
        S.push(tmp);
        sum += get(tmp);
        sol += sum;
    }
    return sol;
}

void solve() {
    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        vector <int> tmp;
        for (int i = l; i < r; i++)
            tmp.push_back(abs(a[i + 1] - a[i]));
        printf("%I64d\n", calc(tmp));
    }
}

int main() {
    load();
    solve();
    return 0;
}