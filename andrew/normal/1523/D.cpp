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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const ll MAX = 1e18 + 1000000;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int dp[MAXN];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, P;

    cin >> n >> m >> P;

    vector <string> s(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector <int> p(n);

    iota(all(p), 0);

    shuffle(all(p), rnd);

    vector <int> musk(n);

    string ans;

    int valAns = 0;

    for(int step = 0; step < min(10, n); step++){
        vector <int> v;
        for(int j = 0; j < m; j++){
            if(s[p[step]][j] == '1'){
                v.p_b(j);
            }
        }
        int len = v.size();
        fill(dp, dp + pw(len), 0);
        for(int i = 0; i < n; i++){
            musk[i] = 0;
            for(int j = 0; j < len; j++){
                if(s[i][v[j]] == '1'){
                    musk[i] |= pw(j);
                }
            }
            dp[musk[i]]++;
        }
        int res = 0;
        for(int j = 0; j < len; j++){
            for(int i = 0; i < pw(len); i++){
                if((i & pw(j))){
                    dp[i ^ pw(j)] += dp[i];
                }
            }
        }
        for(int i = 0; i < pw(len); i++)if(dp[i] * 2 >= n){
            if(__builtin_popcount(i) > __builtin_popcount(res)){
                res = i;
            }
        }
        string sRes;
        sRes.resize(m);
        fill(all(sRes), '0');
        for(int i = 0; i < len; i++){
            if((res & pw(i))){
                sRes[v[i]] = '1';
            }
        }
        if(ans.empty() || __builtin_popcount(res) > valAns){
            valAns = __builtin_popcount(res);
            ans = sRes;
        }
    }

    cout << ans << "\n";

    return 0;
}