#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ll int

using namespace std;
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

ll translate(string s){
    ll res = 0;
    for(int i = 0; i < s.size(); i++)res |= (1ll << i) * (s[i] - '0');
    return res;
}
vector <ll> kek[5001];
ll sum[5001][101];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m, q;
    cin >> n >> m >> q;
    string s;
    ll k = 1ll << n;
    vector <ll> b(n);
    for(int i = 0; i < n; i++)cin >> b[i];
    vector <ll> a(k);
    for(int i = 0; i < m; i++){
        cin >> s;
        a[translate(s)]++;
    }
    for(int i = 0; i < k; i++)
    for(int j = 0; j < k; j++){
        ll sc = 0;
        for(int i1 = 0; i1 < n; i1++){
            ll ra = (1ll << i1) & i;
            ll rb = (1ll << i1) & j;
            if(ra == rb)sc += b[i1];
        }
        if(sc < 101)sum[i][sc] += a[j];
    }
    for(int i = 0; i < k; i++){
        kek[i].resize(101);
        ll sc = 0;
        for(int j = 0; j < 101; j++){
            sc += sum[i][j];
            kek[i][j] = sc;
        }
    }
    while(q--){
        ll xe;
        cin >> s >> xe;
        ll x = translate(s);
        ll ans = kek[x][xe];
        cout << ans << "\n";
    }
    return 0;
}