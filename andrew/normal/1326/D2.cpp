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
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll inf = 3e9;
const ll mod = 998244353;
const ll N = 1e6;
const ll mod1 = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll h[MAXN], h1[MAXN], st[MAXN], ob[MAXN], st1[MAXN], ob1[MAXN];
ll h2[MAXN], h3[MAXN];

ll bp(ll a, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

pll get(ll l, ll r){
    pll res;
    if(l > r)return {0, 0};
    res.fi = (h[r] - h[l - 1] + mod) % mod;
    (res.fi *= ob[l]) %= mod;
    res.se = (h1[r] - h1[l - 1] + mod1) % mod1;
    (res.se *= ob1[l]) %= mod1;
    return res;
}

pll get1(ll l, ll r){
    pll res;
    if(l > r)return {0, 0};
    res.fi = (h2[r] - h2[l - 1] + mod) % mod;
    (res.fi *= ob[l]) %= mod;
    res.se = (h3[r] - h3[l - 1] + mod1) % mod1;
    (res.se *= ob1[l]) %= mod1;
    return res;
}

pll mb, mb1;
int n;

bool check(ll l, ll r){
     mb = {h[l], h1[l]};
    (mb.fi *= ob[1]) %= mod;
    (mb.se *= ob1[1]) %= mod1;
    (mb.fi += st[l] * get(r, n).fi) %= mod;
    (mb.se += st1[l] * get(r, n).se) %= mod1;
    mb1 = get1(1, n - r + 1);
    (mb1.fi += st[n - r + 1] * get1(n - l + 1, n).fi) %= mod;
    (mb1.se += st1[n - r + 1] * get1(n - l + 1, n).se) %= mod1;
    return (mb == mb1);
}

void main_solve(){
    string s, ans;
    cin >> s;

    n = sz(s);

    h[0] = 0;
    h1[0] = 0;
    for(int i = 1; i <= n; i++){
        h[i] = (h[i - 1] + st[i] * (s[i - 1] - 'a' + 1)) % mod;
        h1[i] = (h1[i - 1] + st1[i] * (s[i - 1] - 'a' + 1)) % mod1;

        h2[i] = (h2[i - 1] + st[i] * (s[n - i] - 'a' + 1)) % mod;
        h3[i] = (h3[i - 1] + st1[i] * (s[n - i] - 'a' + 1)) % mod1;
    }

    pll mb = {0, 0}, mb1;
    int res = 0;
    for(int r = 1; r <= n; r++)if(check(0, r))res = max(res, n - r + 1);
    for(int r = 1; r <= n; r++)if(check(r, n + 1))res = max(res, r);
    ll it = 0;
    while(it < n && s[it] == s[n - it - 1])++it;
    for(int l = 1; l <= n / 2; l++){
        if(it >= l){
            if(2 * l <= n)res = max(res, l * 2);
            if(2 * l < n)res = max(res, l * 2 + 1);
        }else{
            if(check(2 * l - it, n - it + 1))res = max(res, l * 2);
            if(l * 2 < n && check(2 * l - it + 1, n - it + 1))res = max(res, l * 2 + 1);
        }
    }

    for(int r = 1; r <= n; r++)if((n - r + 1) * 2 <= n){
        if(it < (n - r + 1)){
            if(check(it, n - ((n - r + 1) * 2 - it) + 1))res = max(res, (n - r + 1) * 2);
            if((n - r + 1) * 2 < n && check(it, n - ((n - r + 1) * 2 + 1 - it) + 1))res = max(res, (n - r + 1) * 2 + 1);
        }
    }


    for(int r = 1; r <= n; r++)if(check(r, n + 1) && res == r){
        string ans = s.substr(0, r);
        fout(ans);
    }

    for(int r = 1; r <= n; r++)if(check(0, r) && res == n - r + 1){
        string ans = s.substr(r - 1);
        fout(ans);
    }


    for(int l = 1; l <= n / 2; l++){
        if(it >= l){
            if(2 * l <= n && res == 2 * l){
                string mb = s.substr(0, l);
                string ans = mb;
                reverse(all(mb));
                ans += mb;
                fout(ans);
            }
            if(2 * l < n && res == 2 * l + 1){
                string mb = s.substr(0, l);
                string ans = mb;
                ans += s[l];
                reverse(all(mb));
                ans += mb;
                fout(ans);
            }
        }else{
            if(check(2 * l - it, n - it + 1) && 2 * l == res){
                string mb = s.substr(0, l);
                string ans = mb;
                reverse(all(mb));
                ans += mb;
                fout(ans);
            }
            if(l * 2 < n && check(2 * l - it + 1, n - it + 1) && 2 * l + 1 == res){
                string mb = s.substr(0, l);
                string ans = mb;
                ans += s[l];
                reverse(all(mb));
                ans += mb;
                fout(ans);
            }
        }
    }
    for(int r = 1; r <= n; r++)if((n - r + 1) * 2 <= n){
        if(it < (n - r + 1)){
            if(check(it, n - ((n - r + 1) * 2 - it) + 1) && res == (n - r + 1) * 2){
                string mb = s.substr(n - ((n - r + 1)));
                string ans = mb;
                reverse(all(mb));
                ans = mb + ans;
                fout(ans);
            }
            if((n - r + 1) * 2 < n && check(it, n - ((n - r + 1) * 2 + 1 - it) + 1) && res == (n - r + 1) * 2 + 1){
                string mb = s.substr(n - ((n - r + 1)));
                string ans;
                ans += s[n - ((n - r + 1)) - 1];
                ans += mb;
                reverse(all(mb));
                ans = mb + ans;
                fout(ans);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    st[0] = st1[0] = ob[0] = ob1[0] = 1;

    for(int i = 1; i <= N; i++){
        st[i] = (st[i - 1] * 31) % mod;
        st1[i] = (st1[i - 1] * 31) % mod1;
        ob[i] = bp(st[i], mod - 2, mod);
        ob1[i] = bp(st1[i], mod1 - 2, mod1);
    }

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif // LOCAL
    cin >> t;

    for(int id = 1; id <= t; id++){
        #ifdef LOCAL
            cout << "Test number " << id << ":\n";
        #endif // LOCAL
        main_solve();
    }


    return 0;
}