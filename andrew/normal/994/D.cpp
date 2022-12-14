#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    set <pll> l, r;
    ll a, b, mb;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a > b)swap(a, b);
        l.insert({a, b});
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a > b)swap(a, b);
        r.insert({a, b});
    }
    set <ll> kek;
    for(auto i : l)
        for(auto j : r){
            if(i == j)continue;
            bool fll = 0, flr = 0;
            for(auto i1 : r){
                if(i1 == i)continue;
                if(i.fi == i1.fi || i.fi == i1.se)fll = 1;
                if(i.se == i1.fi || i.se == i1.se)flr = 1;
            }
            if(fll && flr)vout(-1);
            fll = flr = 0;
            for(auto i1 : l){
                if(i1 == j)continue;
                if(j.fi == i1.fi || j.fi == i1.se)fll = 1;
                if(j.se == i1.fi || j.se == i1.se)flr = 1;
            }
            if(fll && flr)vout(-1);
            if(i.fi == j.fi)kek.insert(i.fi);
            if(i.fi == j.se)kek.insert(i.fi);
            if(i.se == j.fi)kek.insert(i.se);
            if(i.se == j.se)kek.insert(i.se);
    }
    if(kek.size() == 1)vout(*(kek.begin()));
    vout(0);
    return 0;
}