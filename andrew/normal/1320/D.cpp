#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair <ll, ll>
#define all(x) x.begin(),x.end()
#define pii pair <int, int>
#define sqr(x) ((x)*(x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll pref[MAXN][2];

ll t[3][MAXN];

ll st[3][N + 10], ob[3][N + 10];
ll mod[3];

void u(ll xe, ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i){
        (t[xe][i] += val) %= mod[xe];
    }
}

ll f(ll xe, ll pos){
    ll res = 0;
    for(int i = pos; i > 0; i -= i & -i){
        (res += t[xe][i]) %= mod[xe];
    }
    return res;
}

ll get(ll xe, ll l, ll r){
    return (f(xe, r) - f(xe, l - 1) + mod[xe]) % mod[xe];
}

ll bp(ll a, ll n, ll m){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    mod[0] = 1e9 + 7;
    mod[1] = 998244353;
    mod[2] = 1e9 + 9;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    ll n;
    cin >> n;
    string t;
    cin >> t;

    vector <ll> a(n + 1);

    st[0][0] = 1;
    st[1][0] = 1;
    st[2][0] = 1;
    ob[0][0] = 1;
    ob[1][0] = 1;
    ob[2][0] = 1;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++)st[j][i] = (st[j][i - 1] * 2) % mod[j];
        for(int j = 0; j < 3; j++)ob[j][i] = bp(st[j][i], mod[j] - 2, mod[j]);
    }

    ll pos = 0, sc = 0;

    for(int i = 1; i <= n; i++){
        a[i] = t[i - 1] - '0';
        pref[i][0] = pref[i - 1][0];
        pref[i][1] = pref[i - 1][1];
        pref[i][a[i]]++;
        if(a[i] == 0){
            if(sc){
                u(0, i, st[0][pos]);
                u(1, i, st[1][pos]);
                u(2, i, st[2][pos]);
            }
            pos++;
        }else sc ^= 1;
    }


    ll q;
    cin >> q;

    while(q--){
        ll l, l1, len;
        cin >> l >> l1 >> len;
        if(pref[l + len - 1][0] - pref[l - 1][0] != pref[l1 + len - 1][0] - pref[l1 - 1][0]){
            cout << "No\n";
            continue;
        }
        ll h1, h2, h3;
        ll H1, H2, H3;
        h1 = get(0, l, len + l - 1) * ob[0][pref[l - 1][0]];
        h1 %= mod[0];
        if(pref[l - 1][1] % 2){
            h1 = (st[0][pref[l + len - 1][0] - pref[l - 1][0]] - h1 + mod[0]) % mod[0];
            h1--;
            if(h1 < 0)h1 += mod[0];
        }
        h2 = get(1, l, len + l - 1) * ob[1][pref[l - 1][0]];
        h2 %= mod[1];
        if(pref[l - 1][1] % 2){
            h2 = (st[1][pref[l + len - 1][0] - pref[l - 1][0]] - h2 + mod[1]) % mod[1];
            h2--;
            if(h2 < 0)h2 += mod[1];
        }
        h3 = get(2, l, len + l - 1) * ob[2][pref[l - 1][0]];
        h3 %= mod[2];
        if(pref[l - 1][1] % 2){
            h3 = (st[2][pref[l + len - 1][0] - pref[l - 1][0]] - h3 + mod[2]) % mod[2];
            h3--;
            if(h3 < 0)h3 += mod[2];
        }
        H1 = h1, H2 = h2, H3 = h3;
        l = l1;
        h1 = get(0, l, len + l - 1) * ob[0][pref[l - 1][0]];
        h1 %= mod[0];
        if(pref[l - 1][1] % 2){
            h1 = (st[0][pref[l + len - 1][0] - pref[l - 1][0]] - h1 + mod[0]) % mod[0];
            h1--;
            if(h1 < 0)h1 += mod[0];
        }
        h2 = get(1, l, len + l - 1) * ob[1][pref[l - 1][0]];
        h2 %= mod[1];
        if(pref[l - 1][1] % 2){
            h2 = (st[1][pref[l + len - 1][0] - pref[l - 1][0]] - h2 + mod[1]) % mod[1];
            h2--;
            if(h2 < 0)h2 += mod[1];
        }
        h3 = get(2, l, len + l - 1) * ob[2][pref[l - 1][0]];
        h3 %= mod[2];
        if(pref[l - 1][1] % 2){
            h3 = (st[2][pref[l + len - 1][0] - pref[l - 1][0]] - h3 + mod[2]) % mod[2];
            h3--;
            if(h3 < 0)h3 += mod[2];
        }
        if(H1 == h1 && H2 == h2 && H3 == h3)cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}