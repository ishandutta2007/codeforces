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
    set <ll> s;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        s.insert(x);
    }
    s.insert(0);
    s.insert(m);
    ll kol = 0;
    vector <ll> in, off;
    ll smi, smo;
    smi = smo = 0;
    set <ll> :: iterator it = s.begin();
    ++it;
    ll last = 0;
    for(; it != s.end(); ++it, kol++){
        ll x = *it;
        if(kol % 2 == 0){
            in.p_b(x - last);
            smi += in.back();
        }else{
            off.p_b(x - last);
            smo += off.back();
        }
        last = x;
    }
    ll ans = smi;
    reverse(all(in));
    reverse(all(off));
    it = s.begin();
    kol = 0;
    ll sum = 0;
    for(; it != s.end(); ++it, kol++){
        ll x = *it;
        if(kol % 2 == 0 && kol > 0){
            smo -= off.back();
            off.pop_back();
        }
        if(kol % 2 == 1){
            smi -= in.back();
            sum += in.back();
            in.pop_back();
        }
        if(s.find(x + 1) != s.end())continue;
        ans = max(ans, smo - 1 + sum);
    }
    cout << ans << "\n";
    return 0;
}