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

set <ll> mb;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    if(n == 1)vout(a[0] % m);

    ll ans = 0;
    ll _first = n / 2, _second = n - n / 2;

    ll musk = 1ll << _first;

    for(int i = 1; i < musk; i++){
        ll sc = 0;
        for(int j = 0; j < _first; j++)if(((1ll << j) & i))sc = (sc + a[j]) % m;
        ans = max(ans, sc);
        mb.insert(sc);
    }

    musk = 1ll << _second;
    for(int i = 1; i < musk; i++){
        ll sc = 0;
        for(int j = 0; j < _second; j++)if(((1ll << j) & i))sc = (sc + a[j + _first]) % m;
        ans = max(ans, sc);
        ans = max(ans, (sc + *(--mb.end())) % m);
        ans = max(ans, (sc + *mb.begin()) % m);
        ll kek = m - sc;
        set <ll> :: iterator it = mb.lower_bound(kek);
        if(it != mb.begin()){
            --it;
            ans = max(ans, (sc + *it) % m);
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}