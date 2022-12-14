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
typedef unsigned long long ll;
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
vector <pll> v[MAXN];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    ll y = 0;
    for(int i = 1; i <= n; i++){
        v[i].p_b({y + i, i});
    }
    y += n;
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b({y + a, a});
        v[b].p_b({y + b, b});

        v[a].p_b({y + b, a});
        //v[b].p_b({y + b, a});
        y += n;
    }

    for(int i = 1; i <= n; i++){
        cout << v[i].size() << "\n";
        for(auto j : v[i])cout << j.fi << " " << j.se << "\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}