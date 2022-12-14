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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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

ll bel(ll y, ll x, ll y1, ll x1){
    ll kol1 = ((x1 + 1) / 2) - (x / 2);
    ll kol2 = x1 / 2 - ((x - 1) / 2);

    ll len = y1 - y + 1;

    if(y % 2){
        return ((len + 1) / 2) * kol1 + len / 2 * kol2;
    }else{
        return ((len + 1) / 2) * kol2 + len / 2 * kol1;
    }

}

ll chern(ll y, ll x, ll y1, ll x1){
    ll kol1 = (x1 / 2) - ((x - 1) / 2);
    ll kol2 = (x1 + 1) / 2 - ((x) / 2);

    ll len = y1 - y + 1;

    if(y % 2){
        return ((len + 1) / 2) * kol1 + len / 2 * kol2;
    }else{
        return ((len + 1) / 2) * kol2 + len / 2 * kol1;
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        ll y1, x1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll y3, x3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        ll ans = 0;
        ll ansb = bel(1, 1, n, m);
        ll ansc = chern(1, 1, n, m);

        //cout << ansb << " " << ansc << "\n";

        ansc -= chern(y1, x1, y2, x2);
        ansb += chern(y1, x1, y2, x2);
        //cout << ansb << " " << ansc << "lel\n";
        ansb -= bel(y3, x3, y4, x4);
        ansc += bel(y3, x3, y4, x4);

        //cout << ansb << " " << ansc << "lel\n";

        if(y3 <= y1 && y1 <= y4){
            ll yo1 = y1, yo2 = min(y2, y4);
            if(x3 <= x1 && x1 <= x4){
                ll xo1 = x1, xo2 = min(x2, x4);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
            else if(x3 <= x2 && x2 <= x4){
                ll xo1 = x3, xo2 = x2;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x3 && x3 <= x2){
                ll xo1 = x3, xo2 = min(x4, x2);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x4 && x4 <= x2){
                ll xo1 = x1, xo2 = x4;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
        }
        else if(y3 <= y2 && y2 <= y4){
            ll yo1 = y3, yo2 = y2;
            if(x3 <= x1 && x1 <= x4){
                ll xo1 = x1, xo2 = min(x2, x4);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
            else if(x3 <= x2 && x2 <= x4){
                ll xo1 = x3, xo2 = x2;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x3 && x3 <= x2){
                ll xo1 = x3, xo2 = min(x4, x2);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x4 && x4 <= x2){
                ll xo1 = x1, xo2 = x4;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
        }
        else if(y1 <= y3 && y3 <= y2){
            ll yo1 = y3, yo2 = min(y2, y4);
            if(x3 <= x1 && x1 <= x4){
                ll xo1 = x1, xo2 = min(x2, x4);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
            else if(x3 <= x2 && x2 <= x4){
                ll xo1 = x3, xo2 = x2;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x3 && x3 <= x2){
                ll xo1 = x3, xo2 = min(x4, x2);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x4 && x4 <= x2){
                ll xo1 = x1, xo2 = x4;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
        }
       else if(y1 <= y4 && y4 <= y2){
            ll yo1 = y1, yo2 = y4;
            if(x3 <= x1 && x1 <= x4){
                ll xo1 = x1, xo2 = min(x2, x4);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
            else if(x3 <= x2 && x2 <= x4){
                ll xo1 = x3, xo2 = x2;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x3 && x3 <= x2){
                ll xo1 = x3, xo2 = min(x4, x2);
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }else if(x1 <= x4 && x4 <= x2){
                ll xo1 = x1, xo2 = x4;
                ansc += chern(yo1, xo1, yo2, xo2);
                ansb -= chern(yo1, xo1, yo2, xo2);
            }
        }


        cout << ansb << " " << ansc << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}