#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, M;
vector <int> V;
int len[MAXN];
int per[MAXN], num[MAXN];

void load() {
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int t, l, c;
        scanf("%d%d", &t, &l);
        len[i] = 1;
        if (t == 1) {
            V.push_back(l);
            num[i] = l;
        }
        else {
            scanf("%d", &c);
            len[i] = l * c;
            per[i] = l;
            for (int j = 0; j < len[i] && V.size() < MAXN; j++)
                 V.push_back(V[j % l]);
        }
    }
}

int solve() {
    scanf("%d", &N);
    int pos = 0;
    ll sum = 0;
    while (N--) {
        ll x;
        scanf("%I64d", &x);
        for (x--; sum + (ll)len[pos] <= x; pos++)
            sum += (ll)len[pos];
        printf("%d ", per[pos] ? V[(x - sum + (ll)len[pos]) % (ll)per[pos]] : num[pos]);
    }   
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}