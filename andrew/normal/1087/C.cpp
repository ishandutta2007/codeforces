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

set <pll> res;

void way(ll xf, ll yf, ll xt, ll yt){
    while(xf != xt || yf != yt){
        res.insert({xf, yf});

        if(xf != xt){
            if(xf < xt)xf++; else xf--;
        }else{
            if(yf < yt)yf++; else yf--;
        }

    }
    res.insert({xt, yt});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    vector <ll> x(3), y(3);

    for(int i = 0; i < 3; i++)cin >> x[i] >> y[i];

    ll ans = 1e18;

    vector <ll> p(3);

    for(int i = 0; i < 3; i++)p[i] = i;

    do{
        ll sc = 0;

        for(int i = 1; i < 3; i++)sc += abs(x[p[i]] - x[p[i - 1]]) + abs(y[p[i]] - y[p[i - 1]]);

        ans = min(ans, sc);

    }while(next_permutation(p.begin(), p.end()));

    for(int i = 0; i <= 1000; i++)
    for(int j = 0; j <= 1000; j++){
        ll sc = 0;

        for(int i1 = 0; i1 < 3; i1++)sc += abs(x[i1] - i) + abs(y[i1] - j);
        ans = min(ans, sc);
    }

    sort(p.begin(), p.end());
    do{
        ll sc = 0;

        for(int i = 1; i < 3; i++)sc += abs(x[p[i]] - x[p[i - 1]]) + abs(y[p[i]] - y[p[i - 1]]);

        if(ans == sc){
            for(int i = 1; i < 3; i++)way(x[p[i - 1]], y[p[i - 1]], x[p[i]], y[p[i]]);
            cout << res.size() << "\n";
            for(auto i : res)cout << i.fi << " " << i.se << "\n";
            return 0;
        }

    }while(next_permutation(p.begin(), p.end()));

    for(int i = 0; i <= 1000; i++)
    for(int j = 0; j <= 1000; j++){
        ll sc = 0;

        for(int i1 = 0; i1 < 3; i1++)sc += abs(x[i1] - i) + abs(y[i1] - j);

        if(ans == sc){
            for(int i1 = 0; i1 < 3; i1++)way(i, j, x[i1], y[i1]);
            cout << res.size() << "\n";
            for(auto jj : res)cout << jj.fi << " " << jj.se << "\n";
            return 0;
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}