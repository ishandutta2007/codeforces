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
    ll le = -1e9, ri = 1e9;
    ll n, h;
    cin >> n >> h;
    vector <pll> ans(n);
    vector <ll> a(n);
    ll l1 = le;
    ll pref = 0;
    for(int i = 0; i < n; i++){
        cin >> ans[i].fi >> ans[i].se;
        pref += ans[i].fi - l1;
        l1 = ans[i].se;
        a[i] = pref;
    }
    pref = 0, l1 = le;
    ll answer = 0;
    for(int i = 0; i < n; i++){
        pref += ans[i].fi - l1;
        l1 = ans[i].se;
        ll to = h + pref;
        ll kek = upper_bound(all(a), to) - a.begin();
        kek--;
        if(to == a[kek])kek--;
        ll res = ans[kek].se - ans[i].fi;
        to -= a[kek];
        res += to;
        answer = max(answer, res);
    }
    cout << answer << "\n";
    return 0;
}