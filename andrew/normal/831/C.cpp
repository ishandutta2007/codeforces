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

set <ll> ans;
multiset <ll> mb;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("flag.in","r",stdin);
    //freopen("flag.out","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    vector <ll> b(m);
    for(int i = 0; i < m; i++)cin >> b[i];
    ll sc = 0;
    for(int i = 0; i < n; i++){
        sc += a[i];
        mb.clear();
        for(int j = 0; j < m; j++)mb.insert(b[j]);

        ll x = b[0] - sc;
        ll kek = x;
        for(int j = 0; j < n; j++){
            x += a[j];
            if(mb.find(x) != mb.end())mb.erase(mb.find(x));
        }
        if(mb.empty())ans.insert(kek);
    }
    cout << ans.size() << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}