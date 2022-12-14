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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll ans = 0;

ll last_time[MAXN], zapros;

void sol(vector <ll> &a, ll l, ll r){
    if(l == r){
        ans += (a[l] == 1);
        return;
    }
    ll mid = (l + r) >> 1;
    ll ca, cb;
    ca = cb = 0;
    vector <ll> vl, vr;

    ++zapros;
    for(int i = mid + 1; i <= r; i++){
        if(last_time[a[i]] == zapros)break;
        last_time[a[i]] = zapros;
        vr.p_b(a[i]);
    }

    ++zapros;
    for(int i = mid; i >= l; i--){
        if(last_time[a[i]] == zapros)break;
        last_time[a[i]] = zapros;
        vl.p_b(a[i]);
    }

    ++zapros;

    vector <ll> us = vl, pref(sz(vl), 0);
    for(int i : us)last_time[i] = zapros;
    for(int i = 0; i < sz(pref); i++){
        pref[i] = max(us[i], (!i ? 0 : pref[i - 1]));
    }

    int kol = 0, mx = 0, was_add = 0;

    for(int i : vr){
        kol++;
        mx = max(mx, i);
        while(last_time[i] == zapros){
            last_time[us.back()] = 0;
            us.pop_back();
        }
        if(sz(us) >= mx - kol && mx - kol > 0 && pref[mx - kol - 1] < mx){
            ans++;
            was_add++;
        }
    }

    ++zapros;

    us = vr;
    pref.resize(sz(vr));
    for(int i : us)last_time[i] = zapros;
    for(int i = 0; i < sz(pref); i++){
        pref[i] = max(us[i], (!i ? 0 : pref[i - 1]));
    }

    kol = 0, mx = 0;


    for(int i : vl){
        kol++;
        mx = max(mx, i);
        while(last_time[i] == zapros){
            last_time[us.back()] = 0;
            us.pop_back();
        }
        if(sz(us) >= mx - kol && mx - kol > 0 && pref[mx - kol - 1] < mx){
            ans++;
        }
    }

    sol(a, l, mid);
    sol(a, mid + 1, r);

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

    vector <ll> a(n);
    for(auto &i : a)cin >> i;

    sol(a, 0, n - 1);

    cout << ans << "\n";

    return 0;
}