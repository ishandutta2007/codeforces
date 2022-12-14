#include <bits/stdc++.h>

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
#define fout(x) {cout << x; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 4e5 + 5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int z[N];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> dp(n + 1);
    int x, uk;
    string c;
    for(int i = 0; i < n; i++){
        dp[i] = n - i;
        c = s.substr(i) + '#' + s;
        z[0] = 0;
        for(int j = 1, l = 0, r = 0; j < c.size(); j++){
            z[j] = 0;
            if(j <= r){
                z[j] = min(r - j + 1, z[j - l]);
            }
            while(j + z[j] < c.size() && c[z[j]] == c[j + z[j]]){
                z[j]++;
            }
            if(j + z[j] - 1 > r){
                l = j, r = j + z[j] - 1;
            }
        }
        for(int j = 0; j < i; j++){
            uk = z[(n - i) + 1 + j];
            if(uk != n - i && s[i + uk] > s[j + uk]){
                dp[i] = max(dp[i], dp[j] + (n - i) - uk);
            }
        }
    }
    cout << *max_element(all(dp)) << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}