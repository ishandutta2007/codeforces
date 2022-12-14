#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 3000 + 5;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s) {cout << s << endl; exit(0);}

ll dp[N][2];

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 0; i <= n; i++){
        dp[i][0] = dp[i][1] = inf;
    }

    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        if(i + 2 <= n)dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
        int s = a[i + 1];
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + s);
        if(i + 2 <= n){
            s += a[i + 2];
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + s);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);    

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){ 
        solve();
    }
  
    return 0;
}