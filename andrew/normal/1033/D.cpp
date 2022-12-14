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
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
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

ll f(ll x){
    ll l = sqrt(x);
    while(l * l > x)l--;
    while(l * l < x)l++;
    return l;
}

ll f1(ll x){
    ll l = pow(x, 1 / 3.0);
    while(l * l * l < x)l++;
    return l;
}

map <ll, ll> mp;
const ll MOD = 998244353;
ll pod[MAXN];
map <ll, pll> mp1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> clr;
    for(int i = 0; i < n; i++){
        ll x, a;
        cin >> x;
        a = f(x);
        if(sqr(a) == x){
            ll b = f(a);
            if(b * b == a)mp[b] += 4; else{
                mp[a] += 2;
            }
        }else{
            a = f1(x);
            if(a * a * a == x)mp[a] += 3; else clr.p_b(x);
        }
    }

    for(int i = 0; i < clr.size(); i++){
        for(int j = 0; j < clr.size(); j++)if(clr[i] != clr[j] && __gcd(clr[i], clr[j]) > 1){
            ll x = __gcd(clr[i], clr[j]);
            if(mp.find(x) == mp.end())mp[x] = 0;
        }
    }
    ll ans = 1;
    for(auto i : mp){
        ll x = i.fi, res = i.se + 1;
        for(int j = 0; j < clr.size(); j++)if(clr[j] % x == 0){
            res++;
            clr[j] /= x;
            pod[j]++;
        }
        res %= MOD;
        ans = (ans * res) % MOD;
    }
    for(int i = 0; i < clr.size(); i++)if(pod[i] != 2){
        mp1[clr[i]].fi++;
        mp1[clr[i]].se = pod[i];
    }
    for(auto i : mp1){
        pll xe = i.se;
        ll kol = xe.fi, val = xe.se;
        ll res = 0;
        if(val == 1){
            res = kol + 1;
        }else res = ((kol + 1) * (kol + 1)) % MOD;

        ans = (ans * res) % MOD;
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}