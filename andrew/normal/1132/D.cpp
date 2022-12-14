#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll a[MAXN], b[MAXN], c[MAXN], last[MAXN];

vector <pll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll l = 0, r = 1e18;

    ll n, k;
    cin >> n >> k;

    set <pll> s;

    int i;
    for(i = 0; i < n; i++)cin >> a[i];
    for(i = 0; i < n; i++)cin >> b[i];

    ll mi = 1e18;
    for(i = 0; i < n; i++)c[i] = a[i];
    for(i = 0; i < n; i++)s.insert({c[i] / b[i] + 1, i});
    for(i = 0; i < n; i++)last[i] = 1;
    bool fl = 1;
    set <pll> :: iterator it;
    for(int i = 1; i <= k; i++){
        pll xe = *s.begin();
        s.erase(s.begin());
        if(xe.fi >= k)break;
        if(xe.fi < i){
            fl = 0;
            break;
        }
        ll ot = c[xe.se];
        ot -= b[xe.se] * (i - last[xe.se]);
        ot += mi;
        ot -= b[xe.se];
        if(i < k && ot < 0){
            fl = 0;
            break;
        }
        if(ot > 1e18)ot = 1e18;
        xe.fi = i + ot / b[xe.se] + 1;
        last[xe.se] = i + 1;
        c[xe.se] = ot;
        s.insert(xe);
    }

    if(!fl)vout(-1);

    while(l < r){
        ll mi = (l + r) >> 1;
        for(i = 0; i < n; i++)c[i] = a[i];

        for(int i = 1; i <= k; i++)v[i].clear();

        for(int i = 0; i < n; i++){
            if(c[i] / b[i] + 1 < k)v[c[i] / b[i] + 1].p_b({c[i] / b[i] + 1, i});
        }

        for(i = 0; i < n; i++)last[i] = 1;
        bool fl = 1;
        ll kol = 0;
        for(int i = 1; i < k; i++){
            kol++;
            if(v[i].size() > kol){
                fl = 0;
                break;
            }

            for(auto xe : v[i]){
                kol--;
                if(kol < 0){
                    fl = 0;
                    break;
                }
                ll ot = c[xe.se];
                ot -= b[xe.se] * (i - last[xe.se]);
                ot += mi;
                ot -= b[xe.se];
                while(ot < 0 && kol){
                    ot += mi;
                    kol--;
                }
                if(ot < 0){
                    fl = 0;
                    break;
                }
                if(ot > 1e18)ot = 1e18;
                xe.fi = i + ot / b[xe.se] + 1;
                if(xe.fi >= k)continue;
                v[xe.fi].p_b(xe);
                last[xe.se] = i + 1;
                c[xe.se] = ot;
            }
            if(!fl)break;

        }

        if(fl)r = mi; else l = mi + 1;
    }

    cout << l << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}