#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

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

set <pair <ll, pll> > s;

ll a[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    n *= 2;
    vector <ll> ans(n + 1);

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            cin >> a[i][j];
            s.insert({a[i][j], {i, j}});
        }
    }

    while(!s.empty()){
        pair <ll, pll> xe = *(--s.end());
        ans[xe.se.fi] = xe.se.se;
        ans[xe.se.se] = xe.se.fi;
        s.erase(xe);
        ll ra = xe.se.fi, rb = xe.se.se;
        for(int i = 1; i < ra; i++)s.erase({a[ra][i], {ra, i}});
        for(int i = 1; i < rb; i++)s.erase({a[rb][i], {rb, i}});
        for(int i = ra + 1; i <= n; i++)s.erase({a[i][ra], {i, ra}});
        for(int i = rb + 1; i <= n; i++)s.erase({a[i][rb], {i, rb}});
    }
    for(int i = 1; i < n; i++)cout << ans[i] << " ";
    cout << ans[n] << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}