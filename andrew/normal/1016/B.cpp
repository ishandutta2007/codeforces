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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    string s, s1;
    cin >> s >> s1;
    vector <ll> a(n + 1);
    vector <ll> pref(n + 1);
    for(int i = 0; i < n - m + 1; i++){
        bool fl = 0;
        for(int j = 0; j < m; j++)if(s[i + j] != s1[j])fl = 1;
        if(!fl)a[i + 1] = 1;
    }
    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i];
    while(q--){
        ll l, r;
        cin >> l >> r;
        r -= m - 1;
        if(l > r)cout << 0 << endl; else
        cout << pref[r] - pref[l - 1] << "\n";
    }
    return 0;
}