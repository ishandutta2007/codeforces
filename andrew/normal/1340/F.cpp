#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5 + 6;
const ll inf = 2e9;
const ll M = 300000;
const ll mod = 1e9 + 7;
const ll step = 1e5 + 3;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll buben = 1;
ll st[MAXN], ob[MAXN], a[MAXN];

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

ll res;

struct block{
    vector <ll> pref_opened, pref_closed;
    pll borders;
    bool bad;
    ll get_hsh_opened(ll l, ll r){
        ll res = pref_opened[r];
        if(l){
            res = (res - ((pref_opened[l - 1] * st[r - l + 1]) % mod) + mod) % mod;
        }
        return res;
    }
    ll get_hsh_closed(ll l, ll r){
        ll res = pref_closed[r];
        if(l){
            res = (res - pref_closed[l - 1] + mod) % mod;
        }
        (res *= ob[l]) %= mod;
        return res;
    }
};

vector <block> vc;
ll n;

void build(ll idx){
    vector <ll> opened, closed;
    vc[idx].bad = 0;
    for(int i = vc[idx].borders.fi; i <= vc[idx].borders.se; i++){
        if(a[i] < 0){
            if(sz(opened)){
                if(opened.back() != -a[i]){
                    vc[idx].bad = 1;
                    return;
                }else opened.pop_back();
            }else{
                closed.p_b(-a[i]);
            }
        }else{
            opened.p_b(a[i]);
        }
    }
    vc[idx].pref_closed.clear();
    ll temp_hsh = 0;
    for(int i = 0; i < sz(closed); i++){
        (temp_hsh += st[i] * closed[i]) %= mod;
        vc[idx].pref_closed.p_b(temp_hsh);
    }
    temp_hsh = 0;
    vc[idx].pref_opened.clear();
    for(int i = 0; i < sz(opened); i++){
        (temp_hsh *= step) %= mod;
        (temp_hsh += opened[i]) %= mod;
        vc[idx].pref_opened.p_b(temp_hsh);
    }
    opened.clear(), closed.clear();
}

ll was_deleted[MAXN], hsh, hsh1, temp, temp1;

string ans(ll l, ll r){
    if((r - l + 1) % 2)return "No";
    vector <pll> v;
    for(int i = 0; i <= (n - 1) / buben; i++)was_deleted[i] = 0;
    for(int i = l; i <= r; ){
        if(i + buben - 1 <= r && i % buben == 0){
            if(vc[i / buben].bad)return "No";
            ll cnt = 0;
            while(cnt < sz(vc[i / buben].pref_closed)){
                if(v.empty())return "No";
                else{
                    pll xe = v.back();
                    if(xe.se == 1)v.pop_back();
                    if(xe.se == 1){
                        temp = vc[i / buben].get_hsh_closed(cnt, cnt);
                        if(xe.fi != temp)return "No";
                        cnt++;
                    }else{
                        ll len = min(sz(vc[i / buben].pref_closed) - cnt, sz(vc[xe.fi].pref_opened) - was_deleted[xe.fi]);
                        temp = vc[xe.fi].get_hsh_opened(sz(vc[xe.fi].pref_opened) - was_deleted[xe.fi] - len, sz(vc[xe.fi].pref_opened) - 1 - was_deleted[xe.fi]);
                        temp1 = vc[i / buben].get_hsh_closed(cnt, cnt + len - 1);
                        if(temp1 != temp){
                            return "No";
                        }
                        was_deleted[xe.fi] += len;
                        cnt += len;
                        if(was_deleted[xe.fi] == sz(vc[xe.fi].pref_opened))v.pop_back();
                    }
                }
            }

            if(sz(vc[i / buben].pref_opened))v.p_b({i / buben, 0});
            i += buben;
        }else{
            if(a[i] < 0){
                if(v.empty())return "No";
                else{
                    pll xe = v.back();
                    if(xe.se == 1)v.pop_back();
                    if(xe.se == 1){
                        if(xe.fi != -a[i])return "No";
                    }else{
                        temp = vc[xe.fi].get_hsh_opened(sz(vc[xe.fi].pref_opened) - 1 - was_deleted[xe.fi], sz(vc[xe.fi].pref_opened) - 1 - was_deleted[xe.fi]);
                        if(-a[i] != temp){
                            return "No";
                        }
                        was_deleted[xe.fi]++;
                        if(was_deleted[xe.fi] == sz(vc[xe.fi].pref_opened))v.pop_back();
                    }
                }
            }else v.p_b({a[i], 1});
            i++;
        }
    }
    if(v.empty())return "Yes";
    else return "No";
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll k;
    cin >> n >> k;

    st[0] = ob[0] = 1;

    for(int i = 1; i <= 1e5 + 100; i++){
        st[i] = (st[i - 1] * step) % mod;
        ob[i] = bp(st[i], mod - 2);
    }

    while(sqr(buben) < n)buben++;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vc.resize((n - 1) / buben + 1);

    for(int l = 0; l < n; l += buben){
        ll r = l + buben - 1;
        r = min(r, n - 1);
        vc[l / buben].borders = {l, r};
        build(l / buben);
    }

    ll q;
    cin >> q;

    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll pos, x;
            cin >> pos >> x;
            a[pos - 1] = x;
            build((pos - 1) / buben);
        }else{
            ll l, r;
            cin >> l >> r;
            string res = ans(l - 1, r - 1);
            cout << res << "\n";
        }
    }

    return 0;
}