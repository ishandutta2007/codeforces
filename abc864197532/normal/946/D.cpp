#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define endl '\n'
const int N = 510;
vector <int> input[N];
int pre[N][N], dp[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, all;
    cin >> n >> m >> all;
    char c;
    fop (i,0,n) {
        fop (j,0,m) {
            cin >> c;
            if (c == '1') input[i].pb(j);
        }
    }
    fop (i,0,N) fop (j,0,N) pre[i][j] = j ? -864197532 : 0;
    fop (i,0,n) {
        if (input[i].empty()) continue;
        int cost1[N], cost2[N], tmp[N];
        cost1[0] = cost2[0] = 0;
        fop (j,0,input[i].size() - 1) tmp[j] = input[i][j+1] - input[i][j];
        fop (j,0,input[i].size() - 1) cost1[j+1] = cost1[j] + tmp[j];
        fop (j,0,input[i].size() - 1) cost2[j+1] = cost2[j] + tmp[input[i].size() - 2 - j];
        fop (k,0,input[i].size()) {
            fop (l,0,input[i].size()) {
                if (k + l >= input[i].size()) break;
                pre[i][k + l] = max(pre[i][k + l], cost1[k] + cost2[l]);
            }
        }
        pre[i][input[i].size()] = pre[i][input[i].size() - 1] + 1;
    }
    fop (i,0,n) {
        fop (j,0,all+1) {
            if (i) {
                dp[i][j] = -864197532;
                fop (k,0,j+1) dp[i][j] = max(dp[i][j], dp[i - 1][k] + pre[i][j - k]);
            } else {
                dp[i][j] = pre[i][j];
            }
        }
    }
    int ans = 0, aa = 0;
    fop (i,0,n) {
        if (input[i].size()) ans += input[i].back() - input[i][0] + 1;
    }
    fop (i,0,all + 1) aa = max(aa, dp[n - 1][i]);
    cout << ans - aa << endl;
}