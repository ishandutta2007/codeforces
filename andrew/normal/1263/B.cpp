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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector <string> s(n);
        for(int i = 0; i < n; i++)cin >> s[i];
        map <string, bool> mp;
        map <string, bool> f;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            f[s[i]] = 1;
        }
        for(int i = 0; i < n; i++){
            if(f[s[i]]){
                f[s[i]] = 0;
                mp[s[i]] = 1;
                continue;
            }
            ans++;
            string old = s[i];
            for(int j = 0; j < 4; j++){
                do{
                    if(s[i][j] == '9')s[i][j] = '0';
                    else s[i][j]++;
                    if(!mp[s[i]] && !f[s[i]])break;
                }while(old != s[i]);
                if(!mp[s[i]] && !f[s[i]])break;
            }
            mp[s[i]] = 1;
        }
        cout << ans << "\n";
        for(int i = 0; i < n; i++)cout << s[i] << "\n";
    }


    return 0;
}