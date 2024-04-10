#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)      for(int i(a),b_(b);i<b_;++i)
#define REP(i,n)        for(int i=0;i<n;++i)
#define CL(a,x)         memset(a,x,sizeof(a))
#define all(a)          (a).begin(),(a).end()
#define sz(a)           int((a).size())
#define pb              push_back
#define X               first
#define Y               second
using ll =              long long;
using vi =              vector<int>;
using pii =             pair<int, int>;

int n, m, k;
int p[2222];

int f(int i) { return p[i] == i ? i : p[i] = f(p[i]); }

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> k;
    REP (i, n + 1) p[i] = i;
    vi c(k);
    REP (i, k) cin >> c[i];
    REP (i, m) {
        int x, y;
        cin >> x >> y;
        p[f(x)] = f(y);
    }
    vi a, b;
    FOR (i, 1, n + 1) {
        if (p[i] == i) {
            bool ok = false;
            REP (j, k) if (f(c[j]) == i) {
                ok = true;
                break;
            }
            int cnt = 0;
            FOR (j, 1, n + 1) {
                if (f(j) == i)
                    ++cnt;
            }
            (ok ? a : b).pb(cnt);
        }
    }
    sort(all(a));
    for (int x : b) a.back() += x;
    int total = 0;
    for (int x : a) total += x * (x - 1) / 2;
    cout << total - m << endl;
    return 0;
}