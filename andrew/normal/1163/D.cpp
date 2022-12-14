#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll dp[1001][51][51];

ll f(string s){
    int n = s.size();
    vector <int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
		if(i <= r)z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])z[i]++;
		if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
	}
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(i + z[i] == n)ans = max(ans, z[i]);
    }
    return ans;
}

ll pz[101][27], pz1[101][27];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin >> s;
    ll n = s.size();
    s = "+" + s;
    string c, d;
    cin >> c >> d;

    ll a = c.size(), b = d.size();
    string kek;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < 26; j++)if(j != c[i]){
            kek += char(j + 'a');
            pz[i][j] = f(kek);
            kek.erase(kek.size() - 1);
        }
        kek += c[i];
    }

    ll t1 = f(kek);

    kek.clear();

    for(int i = 0; i < b; i++){
        for(int j = 0; j < 26; j++)if(j != d[i]){
            kek += char(j + 'a');
            pz1[i][j] = f(kek);
            kek.erase(kek.size() - 1);
        }
        kek += d[i];
    }

    ll t2 = f(kek);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= a; j++)
        for(int i1 = 0; i1 <= b; i1++)dp[i][j][i1] = -1e18;

    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int op = 0; op < a; op++)
        for(int op1 = 0; op1 < b; op1++){
            if(s[i] == '*'){
                for(int val = 0; val < 26; val++){
                    ll p1, p2;
                    ll sc = dp[i - 1][op][op1];

                    if(val == c[op] - 'a'){
                        p1 = op + 1;
                        if(p1 == a){
                            p1 = t1;
                            sc++;
                        }
                    }else p1 = pz[op][val];

                    if(val == d[op1] - 'a'){
                        p2 = op1 + 1;
                        if(p2 == b){
                            p2 = t2;
                            sc--;
                        }
                    }else p2 = pz1[op1][val];
                    dp[i][p1][p2] = max(dp[i][p1][p2], sc);
                }
            }else{
                ll val = s[i] - 'a';
                ll p1, p2;
                ll sc = dp[i - 1][op][op1];

                if(val == c[op] - 'a'){
                    p1 = op + 1;
                    if(p1 == a){
                        p1 = t1;
                        sc++;
                    }
                }else p1 = pz[op][val];

                if(val == d[op1] - 'a'){
                    p2 = op1 + 1;
                    if(p2 == b){
                        p2 = t2;
                        sc--;
                    }
                }else p2 = pz1[op1][val];
                dp[i][p1][p2] = max(dp[i][p1][p2], sc);
            }
        }
    }

    ll ans = -1e18;

    for(int i = 0; i <= a; i++)
        for(int j = 0; j <= b; j++)ans = max(ans, dp[n][i][j]);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}