#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
string s[55];
int n, m, k;
int a, b, c, d;
set<int> de;
string dp[55][55];
string ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dis[55][55];

void calc(int mask) {
    if(de.count(mask)) return;
    de.insert(mask);
    string bad;
    bad += char('z'+1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = bad;
            dis[i][j] = -1;
        }
    }
    dp[a][b] = "";
    dis[a][b] = 0;
    queue< pair<int, int> > q;
    q.push({a, b});
    vector<pair<int, int> > ord;
    while(q.size() > 0){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        ord.push_back({xx, yy});
        for(int dir = 0; dir < 4; dir++) {
            int x = xx + dx[dir];
            int y = yy + dy[dir];
            if(x >= 0 && x < n && y >= 0 && y < m) {
                char cc = s[x][y];
                if(cc == 'S' || cc == 'T') {
                    if(dis[x][y] == -1) {
                        dis[x][y]=dis[xx][yy] + 1;
                        q.push({x, y});
                    }
                } else if(mask & (1<<(cc-'a'))) {
                    if(dis[x][y] == -1) {
                        dis[x][y]=dis[xx][yy] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    for(auto [xx, yy]: ord){
        if(dis[xx][yy] == 0) {
            dp[xx][yy] = "";
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int x = xx + dx[dir];
            int y = yy + dy[dir];
            if(x >= 0 && x < n && y >= 0 && y < m && dis[xx][yy]==dis[x][y] + 1) {
                char cc = s[xx][yy];
                if(cc == 'S' || cc == 'T') {
                    if(dp[xx][yy] == bad) {
                        dp[xx][yy] = dp[x][y];
                    } else if(dp[xx][yy] > dp[x][y]) {
                        dp[xx][yy] = dp[x][y];
                    }
                } else {
                    if(dp[xx][yy] == bad) {
                        dp[xx][yy] = cc+dp[x][y];
                    } else if(dp[xx][yy] > cc + dp[x][y]) {
                        dp[xx][yy] = cc+dp[x][y];
                    }
                }
            }
        }
    }
    if(dp[c][d] == bad)return;
    if(ans == bad) {
        ans = dp[c][d];
    } else if(ans.size() > dp[c][d].size()) {
        ans = dp[c][d];
    } else if(ans.size() == dp[c][d].size()) {
        ans = min(ans, dp[c][d]);
    }
}
void solve() {
    cin >> n >> m >> k;
    ans = "";
    ans += char('z' + 1);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'T') {
                a = i;
                b = j;
            }
            if(s[i][j] == 'S') {
                c = i;
                d = j;
            }
        }
    }
    //cout << a << " " << b << " " << c << " " << d << "\n";

    for(char a = 'a'; a <= 'z'; a++) {
        for(char b = a; b <= 'z'; b++) {
            for(char c = b; c <= 'z'; c++) {
                for(char d = c; d <= 'z'; d++) {
                    int mask = (1<<(a-'a')) | (1<<(b-'a')) | (1<<(c-'a')) | (1<<(d-'a'));
                    if(__builtin_popcount(mask) != k) continue;
                    //cout << mask << "\n";
                    calc(mask);
                    
                }
            }
        }
    }

    //cout << a << " " << b << " " << c << " " << d << "\n";
    //cout<<ans << "\n";
    if(ans[0] > 'z') {
        cout << -1 << '\n';
    } else {
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}