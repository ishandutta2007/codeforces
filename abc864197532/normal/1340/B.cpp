#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 2087;

string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int ask(string s, string t) { // from s to t
    int aa = 0;
    fop (i,0,7) {
        if (s[i] == '0' and t[i] == '1') aa++;
        if (s[i] == '1' and t[i] == '0') return -1;
    }
    return aa;
}

int main () {
    int n, k;
    cin >> n >> k;
    string s[n];
    fop (i,0,n) cin >> s[i];
    reverse(s, s + n);
    int dp[N][N], pre[n][10];
    fop (i,0,N) fop (j,0,N) dp[i][j] = -1;
    fop (i,0,n) fop (j,0,10) pre[i][j] = ask(s[i], num[j]);
    fop (i,0,n) {
        if (i) {
            fop (j,0,k + 1) {
                FOP (l,10,0) {
                    if (~pre[i][l] and j - pre[i][l] >= 0 and dp[i - 1][j - pre[i][l]] != -1) {
                        dp[i][j] = l;
                        break;
                    }
                }
            }
        } else {
            fop (j,0,10) { 
                if (~pre[i][j]) dp[i][pre[i][j]] = j;
            }
        }
    }
    if (dp[n - 1][k] == -1) {
        cout << -1 << endl;
    } else {
        string ans;
        int now = k;
        FOP (i,n,0) {
            ans.pb(char('0' + dp[i][now]));
            now -= pre[i][dp[i][now]];
        }
        cout << ans << endl;
    }
}