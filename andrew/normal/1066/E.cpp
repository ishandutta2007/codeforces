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

const ll MOD = 998244353;

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res = (res * a) % MOD;
        a = (a * a) % MOD;
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
    string a, b;
    cin >> a >> b;
    ll sum = 0;
    reverse(all(a));
    reverse(all(b));
    while(a.size() < b.size())a += "0";
    while(b.size() < a.size())b += "0";
    n = a.size();
    vector <ll> pref(n + 1);
    for(int i = 0; i < n; i++){
        if(i)pref[i] = pref[i - 1];
        if(a[i] == '1')pref[i] = (pref[i] + bp(2, i)) % MOD;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)if(b[i] == '1'){
        ans = (ans + pref[i]) % MOD;
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}