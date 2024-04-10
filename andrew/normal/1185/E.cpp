#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll MOD = 998244353;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

char c[2011][2011], c1[2011][2011];

ll xmn[126], ymn[126], xmx[126], ymx[126];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                cin >> c[i][j];
                c1[i][j] = '.';
            }

        for(int i = 0; i < 26; i++){
            ymn[i] = xmn[i] = 1e18;
            ymx[i] = xmx[i] = -1e18;
        }

        ll xx, yy;
        ll mx = -1;

        for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)if(c[i][j] != '.'){
            xmn[c[i][j] - 'a'] = min(xmn[c[i][j] - 'a'], i);
            xmx[c[i][j] - 'a'] = max(xmx[c[i][j] - 'a'], i);
            ymn[c[i][j] - 'a'] = min(ymn[c[i][j] - 'a'], j);
            ymx[c[i][j] - 'a'] = max(ymx[c[i][j] - 'a'], j);
            mx = max(mx, ll(c[i][j] - 'a'));
            xx = i;
            yy = j;
        }

        bool fl = 1;

        vector < pair <pll, pll> > res;

        for(int i = 0; i <= mx; i++){
            if(xmn[i] == 1e18){
                for(int i1 = i + 1; i1 <= mx; i1++)if(xmn[i1] != 1e18){
                    xmn[i] = xmx[i] = xmn[i1];
                    ymn[i] = ymx[i] = ymn[i1];
                }

                if(xmn[i] == 1e18){
                    xmn[i] = xmx[i] = xx;
                    ymn[i] = ymx[i] = yy;
                }
            }

            if(xmn[i] != xmx[i] && ymn[i] != ymx[i]){
                fl = 0;
                break;
            }

            for(int y = xmn[i]; y <= xmx[i]; y++)
                for(int x = ymn[i]; x <= ymx[i]; x++)c1[y][x] = char('a' + i);

            res.p_b({{xmn[i], ymn[i]}, {xmx[i], ymx[i]}});
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)if(c[i][j] != c1[i][j])fl = 0;



        if(!fl)cout << "NO\n"; else{
            cout << "YES\n";
            cout << res.size() << "\n";
            for(auto i : res)cout << i.fi.fi << " " << i.fi.se << " " << i.se.fi << " " << i.se.se << "\n";
        }


    }

    return 0;
}