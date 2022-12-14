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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void main_solve(){
    vector <ll> v[26];

    string s, t;
    cin >> s;
    cin >> t;

    for(int i = 0; i < sz(s); i++)v[s[i] - 'a'].p_b(i);
    ll l = 0;
    vector <ll> :: iterator it;
    ll ans = 0;
    ll n = sz(t);
    while(l < n){
        ans++;
        ll pos = 0, x;
        ll last = l;
        while(l < n){
            x = t[l] - 'a';
            it = lower_bound(all(v[x]), pos);
            if(it == v[x].end())break;
            pos = *it + 1;
            l++;
        }
        if(last == l)fout("-1");
    }
    cout << ans << "\n";
    return;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #endif // LOCAL



    return 0;
}