#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    ll n;
    cin >> n;

    vector <ll> x(n), y(n);

    set <pair <ld, ll> > d;

    ld sum = 0, ans = 1e18;

    for(int i = 0; i < n; i++)cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++){
        sum += 2 * sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
        d.insert({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - bx) + sqr(y[i] - by)), i});
    }

    for(int i = 0; i < n; i++){
        ld sc = sum;
        sc -= sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
        sc += sqrt(sqr(x[i] - bx) + sqr(y[i] - by));
        ans = min(ans, sc);
    }

    for(int i = 0; i < n; i++){
        ld sc = sum;
        sc -= sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
        sc += sqrt(sqr(x[i] - ax) + sqr(y[i] - ay));
        ans = min(ans, sc);
    }

    for(int i = 0; i < n; i++){
        ld sc = sum;
        sc -= sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
        sc += sqrt(sqr(x[i] - ax) + sqr(y[i] - ay));
        ans = min(ans, sc);
        d.erase({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - bx) + sqr(y[i] - by)), i});
        if(!d.empty()){
            sc -= (--d.end()) -> fi;
            ans = min(ans, sc);
        }
        d.insert({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - bx) + sqr(y[i] - by)), i});
    }

    d.clear();

    for(int i = 0; i < n; i++){
        d.insert({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - ax) + sqr(y[i] - ay)), i});
    }

    for(int i = 0; i < n; i++){
        ld sc = sum;
        sc -= sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
        sc += sqrt(sqr(x[i] - bx) + sqr(y[i] - by));
        ans = min(ans, sc);
        d.erase({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - ax) + sqr(y[i] - ay)), i});
        if(!d.empty()){
            sc -= (--d.end()) -> fi;
            ans = min(ans, sc);
        }
        d.insert({sqrt(sqr(x[i] - tx) + sqr(y[i] - ty)) - sqrt(sqr(x[i] - ax) + sqr(y[i] - ay)), i});
    }

    cout << fixed << setprecision(7) << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}