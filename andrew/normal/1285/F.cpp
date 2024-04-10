#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5;
const int MAXN = 1123456;
const ll inf = 3e18;
const ll mod = 1000000007;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll cnt[MAXN];
ll last[MAXN];
ll kol[MAXN];
bool is_prime[MAXN];
vector <ll> v;

ll f(ll x){
    while(x != 1){
        int p = last[x];
        v.p_b(p);
        while(x % p == 0)x /= p;
    }
    ll res = 0;
    for(int i = 0; i < pw(sz(v)); i++){
        ll mult = 1;
        bool f = 1;
        for(int j = 0; j < sz(v); j++)if((i & pw(j))){
            f ^= 1;
            mult *= v[j];
        }
        if(f)res += kol[mult];
        else res -= kol[mult];
    }
    v.clear();
    return res;
}

void u(ll x, ll val){
    while(x != 1){
        int p = last[x];
        v.p_b(p);
        while(x % p == 0)x /= p;
    }
    ll res = 0;
    for(int i = 0; i < pw(sz(v)); i++){
        ll mult = 1;
        for(int j = 0; j < sz(v); j++)if((i & pw(j))){
            mult *= v[j];
        }
        kol[mult] += val;
    }
    v.clear();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    fill(is_prime + 2, is_prime + N + 1, 1);

    for(int i = 2; i <= N; i++)if(is_prime[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= N)for(int j = i * i; j <= N; j += i){
            is_prime[j] = 0;
            last[j] = i;
        }
    }

    ll ans = 0;

    while(n--){
        ll x;
        cin >> x;
        if(cnt[x])ans = max(ans, x);
        cnt[x]++;
    }

    vector <ll> v, st;

    for(int i = 1; i <= N; i++){
        v.clear();
        for(int j = 1; j * i <= N; j++)if(cnt[j * i]){
            v.p_b(j);
        }
        reverse(all(v));
        for(auto j : v){
            int fufel = f(j);
            while(!st.empty() && fufel){
                if(__gcd(st.back(), j) == 1){
                    ans = max(ans, ll(st.back()) * ll(i) * ll(j));
                    fufel--;
                }
                u(st.back(), -1);
                st.pop_back();
            }
            st.p_b(j);
            u(st.back(), 1);
        }
        while(!st.empty()){
            u(st.back(), -1);
            st.pop_back();
        }
    }

    cout << ans << "\n";

    return 0;
}