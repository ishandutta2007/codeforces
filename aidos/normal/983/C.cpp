
#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
using namespace std;
int n;
int a[2020];
int b[2020];
int ans = 0;
map<vector<int>, int> M;
int O[1010][11];
int D[1010][11][5];
int dp[2010][750][10];
vector<int> calc(vector<int> d, int x){
    vector<int> u;
    for(int i = 0; i < d.size(); i++) {
        if(d[i] != x) u.push_back(d[i]);
    }
    sort(all(u));
    return u;
}
bool cmp(vector<int> u, vector<int> v){
    return u.size() < v.size();
}
void solve(){
    cin >> n;
    vector<vector<int>>res;
    res.pb(vector<int>());
    for(int i = 1; i <= 9; i++){
        vector< vector<int> > tmp;
        for(int j = 0;j < res.size(); j++){
            if(res[j].size() == 4) continue;
            vector<int> d = res[j];
            while(d.size() < 4){
                d.push_back(i);
                tmp.push_back(d);
            }
        }
        for(int j = 0; j < tmp.size(); j++) res.push_back(tmp[j]);
    }
    sort(all(res), cmp);
    for(int i = 0; i < res.size(); i++){
        M[res[i]] = i;
    }
    for(int i = 0; i < res.size(); i++){
        for(int j = 1; j <= 9; j++){
            vector<int> d = calc(res[i], j);
            O[i][j] = M[d];
        }
        for(int j = 1; j <= 9; j++){
            vector<int> d = res[i];
            int cnt = 0;
            while(d.size() <= 4){
                D[i][j][cnt] = M[d];
                d.push_back(j);
                sort(all(d));
                cnt++;
            }
            while(cnt <= 4){
                D[i][j][cnt] = -1;
                cnt++;
            }
        }
    }
    //cout << res.size() << "\n";
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < res.size(); j++){
            for(int k = 1; k <= 9; k++) dp[i][j][k] = inf;
        }
    }
    dp[0][0][1] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = (int)res.size()-1; j >= 0; j--){
            for(int k = 1; k <= 9; k++){
                for(int t = 1; t <= 9; t++){
                    if(i!=n&&a[i] == t) continue;
                    int g = O[j][k];
                    g = O[g][t];
                    dp[i][g][t] = min(dp[i][g][t], dp[i][j][k] + abs(t-k));
                }
            }
        }
        if(i == n) break;
        for(int j = 0; j < res.size(); j++){
            for(int k = 1; k <= 9; k++){
                int h = O[j][k];
                int g = O[h][a[i]];
                if(res[g].size() == 4) continue;
                int ind = i;
                while (ind < n && res[g].size() < 4 && a[ind] == a[i]){
                    g = D[g][b[ind]][1];
                    ind++;
                }
                dp[ind][g][a[i]] = min(dp[ind][g][a[i]], dp[i][j][k] + abs(k - a[i]));
            }
        }
    }
    int ans = inf;
    for(int i = 1; i <= 9; i++) {
        ans = min(ans, dp[n][0][i]);
    }
    cout << ans + 2 * n<< "\n";
}

int main () {
    //ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}