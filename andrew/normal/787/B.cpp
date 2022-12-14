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

bool f[MAXN], f1[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    while(m--){
        for(int i = 1; i <= n; i++)f[i] = f1[i] = 0;
        ll q;
        cin >> q;
        while(q--){
            ll x;
            cin >> x;
            if(x < 0)f[-x] = 1; else f1[x] = 1;
        }
        bool fl = 0;
        for(int i = 1; i <= n; i++)if(f[i] && f1[i])fl = 1;
        if(!fl)vout("Yes");
    }
    vout("No");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}