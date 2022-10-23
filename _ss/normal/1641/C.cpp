#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10, inf = 1e9;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    set<int> st;
    set<pii> inter;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; ++i) st.insert(i);
    for (int i = 1, t, l, r, x; i <= q; ++i)
    {
        cin >> t >> l;
        if (t == 0)
        {
            cin >> r >> x;
            //cout << i << " " << t << " " << l << " " << r << " " << x << "\n";
            if (x == 0)
            {
                while (true)
                {
                    auto it = st.lower_bound(l);
                    if (*it > r) break;
                    st.erase(it);
                }
            }
            else
            {
                auto it = inter.lower_bound(mp(l, -1));
                if (it != inter.end() && it->se <= r) continue;
                while (true)
                {
                    it = inter.lower_bound(mp(l, inf));
                    if (it == inter.begin()) break;
                    it--;
                    if (it->se < r) break;
                    inter.erase(it);
                }
                inter.insert(mp(l, r));
            }
        }
        else
        {
            if (!st.count(l))
            {
                cout << "NO\n";
                continue;
            }
            auto it = st.find(l);
            it--;
            int u = *it;
            it++;
            it++;
            int v = *it;
            auto it2 = inter.lower_bound(mp(u, inf));
            if (it2 != inter.end() && it2->se < v) cout << "YES\n";
            else cout << "N/A\n";
        }
    }
    //for (pii p : inter) cout << p.fi << " " << p.se << "\n";
    return 0;
}