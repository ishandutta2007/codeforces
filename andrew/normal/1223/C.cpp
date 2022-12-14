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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    while(q--){
        ll n;
        cin >> n;
        vector <ll> a(n + 1);
        vector <bool> fa(n + 1), fb(n + 1);
        for(int i = 1; i <= n; i++)cin >> a[i];
        sort(a.begin() + 1, a.end());
        reverse(a.begin() + 1, a.end());
        ll x, ia, y, ib;
        cin >> x >> ia >> y >> ib;
        ll k;
        cin >> k;
        if(x > y){
            swap(x, y);
            swap(ib, ia);
        }
        ll ca, cb, ans = 0;
        ca = cb = 0;
        ll kol = 0;
        ll kola, kolb;
        kola = kolb = 0;
        for(int i = 1; i <= n; i++){
            if(i % ia == 0)fa[i] = 1, kola++;
            if(i % ib == 0)fb[i] = 1, kolb++;
            if(fa[i] && fb[i])kol++;
        }

        for(int i = 1; i <= kol; i++){
            ca += a[i] / 100 * x;
            cb += a[i] / 100 * y;
            kola--;
            kolb--;
            ans++;
            if(ca + cb >= k)break;
        }

        if(ca + cb < k){
            for(int i = kol + 1; i <= n; i++){
                if(ca + cb < k && kolb){
                    kolb--;
                    cb += a[i] / 100 * y;
                    ans++;
                }else if(ca + cb < k && kola){
                    kola--;
                    ca += a[i] / 100 * x;
                    ans++;
                }
            }
        }

        //cout << ca << " " << cb << " " << k << endl;

        if(ca + cb < k)cout << "-1\n";
        else{
            ll l = 1, r = n;
            while(l < r){
                ll c = (l + r) >> 1;
                ca = cb = 0;
                kol = 0;
                kola = kolb = 0;
                for(int i = 1; i <= c; i++){
                    if(i % ia == 0)fa[i] = 1, kola++;
                    if(i % ib == 0)fb[i] = 1, kolb++;
                    if(fa[i] && fb[i])kol++;
                }

                for(int i = 1; i <= kol; i++){
                    ca += a[i] / 100 * x;
                    cb += a[i] / 100 * y;
                    kola--;
                    kolb--;
                    if(ca + cb >= k)break;
                }

                if(ca + cb < k){
                    for(int i = kol + 1; i <= c; i++){
                        if(ca + cb < k && kolb){
                            kolb--;
                            cb += a[i] / 100 * y;
                        }else if(ca + cb < k && kola){
                            kola--;
                            ca += a[i] / 100 * x;
                        }
                    }
                }
                if(ca + cb >= k)r = c; else l = c + 1;
            }
            cout << l << "\n";
        }

    }

    return 0;
}