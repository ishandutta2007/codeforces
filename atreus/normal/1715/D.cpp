#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Line;

const int MAXN = 2e5 + 10;

int P[MAXN], Q[MAXN], X[MAXN], t[MAXN], a[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> P[i] >> Q[i] >> X[i];
        g[P[i]].push_back(Q[i]);
        g[Q[i]].push_back(P[i]);
    }
    for (int b = 0; b < 30; b++) {
        for (int i = 1; i <= n; i++)
            t[i] = 1;
        for (int i = 0; i < m; i++) {
            if ((X[i] & (1 << b)) == 0) {
                t[P[i]] = 0;
                t[Q[i]] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (t[i] == 0)
                continue;
            bool all_good = true;
            for (auto idx : g[i]) {
                all_good &= t[idx];
                if (idx == i)
                    all_good = false;
            }
            if (all_good)
                t[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            a[i] |= (t[i] << b);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}