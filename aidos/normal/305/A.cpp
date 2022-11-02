#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int dp[maxn];
vector<int> c[2][2];
void solve() {
    cin >> n;
    int cnt100 = 1;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 100) {
            if(cnt100) ans.emplace_back(x);
            cnt100 = 0;
        }else if(x == 0) {
            ans.emplace_back(x);
        }else {
            c[x/10 > 0][x % 10 > 0].emplace_back(x);
        }
    }
    if(c[0][1].size() && c[1][0].size()) {
        ans.emplace_back(c[0][1][0]);
        ans.emplace_back(c[1][0][0]);
    } else {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(c[i][j].size() > 0) {
                    ans.emplace_back(c[i][j][0]);
                    i = 2;
                    break;
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}