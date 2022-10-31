#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}

const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % MOD, b / 2)) % MOD : pw(a * a % MOD, b / 2))); }

ll cnt[30][MAXN][30];

ld P[MAXN];

int main(){
    fast_io;
    cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    string s;
    cin >> s;
    int n = (int)s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            cnt[s[i] - 'a'][(i - j + n) % n][s[j] - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++){
        for(int j = 1; j < n; j++){
            int p = 0, q = 0;
            for(int k = 0; k < 26; k++){
                q += cnt[i][j][k];
                if(cnt[i][j][k] == 1) p++;
            }
            ld BI = 1.0;
            P[i] = max(P[i], BI * p / q);
        }
    }
    ld ans = 0;
    for(int i = 0; i < n; i++) ans += (1.0 / n) * P[s[i] - 'a'];
    cout << ans;
    return 0;
}