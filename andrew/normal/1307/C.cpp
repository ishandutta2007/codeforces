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
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll pref[N][26], suf[N][26];

void main_solve(){
    string s;
    cin >> s;
    ll n = sz(s);
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j < 26; j++){
            pref[i][j] = suf[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++)pref[i][j] = pref[i - 1][j];
        pref[i][s[i - 1] - 'a']++;
    }

    for(int i = n; i > 0; i--){
        for(int j = 0; j < 26; j++)suf[i][j] = suf[i + 1][j];
        suf[i][s[i - 1] - 'a']++;
    }

    ll ans = 0;
    for(int i = 0; i < 26; i++)ans = max(ans, pref[n][i]);
    for(int a = 0; a < 26; a++)
    for(int z = 0; z < 26; z++){
        ll sc = 0;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] - 'a' == a)sc += suf[i + 1][z];
        }
        ans = max(ans, sc);
    }
    fout(ans);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL




    return 0;
}