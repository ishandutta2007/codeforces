#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int f[16];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[1] = 1;
    for (int i = 2; i < 16; ++i)
        f[i] = f[i-1]*i;
    int n, q;
    cin >> n >> q;
    vector<int> pr(n+1);
    for (int i = 0; i < n; ++i)
        pr[i+1] = pr[i]+i+1;
    vector<int> p(min(15LL, n));
    for (int i = p.size()-1; i >= 0; --i)
        p[i] = n-(p.size()-i-1);
    int pos = 1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            int ans = pr[min(r, n-(int)p.size())]-pr[min(l-1, n-(int)p.size())];
            for (int i = max(l-1, n-(int)p.size()); i < r; ++i)
                ans += p[i-(n-p.size())];
            cout << ans << '\n';
        } else {
            int x;
            cin >> x;
            pos += x;
            int pos2 = pos;
            vector<int> nw(p.size());
            for (int i = 0; i < p.size(); ++i)
                nw[i] = i+n-p.size()+1;
            for (int i = 0; i < p.size(); ++i) {
                if (i+1 == p.size()) {
                    p[i] = nw[0];
                    break;
                }
                int k =(pos2-1)/f[(int)p.size()-i-1];
                p[i] = nw[k];
                vector<int> nw2;
                for (int j = 0; j < k; ++j)
                    nw2.pb(nw[j]);
                for (int j = k+1; j < nw.size(); ++j)
                    nw2.pb(nw[j]);
                nw = nw2;
                if (pos2%f[(int)p.size()-i-1] == 0)
                    pos2 = f[(int)p.size()-i-1];
                else
                    pos2 %= f[(int)p.size()-i-1];
            }
        }
    }
    return 0;
}