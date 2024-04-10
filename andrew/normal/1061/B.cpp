#include <bits/stdc++.h>

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
    srand(time(0));

    ll n, m;
    cin >> n >> m;

    ll sc = 0;
    set <ll> s;
    map <ll, ll> mp;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ans += x;
        s.insert(x);
        mp[x]++;
    }

    ll last = 0;

    ll dop = 0;

    for(auto i : s){
        ll kol = i - last;
        if(mp[i] >= kol){
            ans -= kol;
            mp[i] -= kol;
            ans -= mp[i];
            if(mp[i] >= dop){
                dop = 0;
            }else {
                dop -= mp[i];
            }
        }else{
            dop += kol - mp[i];
            ans -= mp[i];
        }
        last = i;
    }
    ans -= dop;
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}