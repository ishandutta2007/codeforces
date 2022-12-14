#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <pll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    while(q--){
        ll n, m;
        cin >> n >> m;
        vector <ll> Par;

        for(int i = 1; i <= m; i++){
            ll a, b;
            cin >> a >> b;
            v[a].p_b({b, i});
            v[b].p_b({a, i});
        }

        vector <bool> f(3 * n + 1);

        for(int i = 1; i <= n * 3; i++)if(!f[i]){
            for(auto j : v[i])if(!f[j.fi]){
                if(Par.size() < n){
                    Par.p_b(j.se);
                }
                f[i] = 1;
                f[j.fi] = 1;
                break;
            }
        }

        if(Par.size() == n){
            cout << "Matching\n";
            for(auto i : Par)cout << i << " ";
            cout << "\n";
        }else{
            cout << "IndSet\n";
            ll kol = n;
            for(int i = 1; i <= 3 * n; i++)if(!f[i] && kol){
                cout << i << " ";
                kol--;
            }
            cout << "\n";
        }
        f.clear();
        for(int i = 1; i <= 3 * n; i++)v[i].clear();
    }


    return 0;
}