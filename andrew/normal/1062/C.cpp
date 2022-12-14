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

const ll MOD = 1e9 + 7;

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

    ll n, q;
    cin >> n >> q;
    vector <ll> a(n + 1), pref(n + 1), f(n + 2), f1(n + 2);
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i];


    while(q--){
        ll l, r;
        cin >> l >> r;
        ll kol1 = pref[r] - pref[l - 1], kol0 = r - l + 1 - kol1;
        if(!kol1)cout << "0\n"; else{
            ll ans = 0;
            //cout << kol1 << " " << kol0 << endl;
            ans = bp(2, kol1);
            ans--;
            if(ans < 0)ans += MOD;
            ll ost = bp(2, kol0) - 1;
            if(ost < 0)ost += MOD;
            ans += (ans * (ost) % MOD) % MOD;
            ans %= MOD;
            cout << ans << "\n";
        }
    }

    return 0;
}