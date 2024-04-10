#include<bits/stdc++.h>
using namespace std;

const int MAX = 6005;
int n;
int dp[MAX][MAX];
map<int, int> conv;
set<int> pts;
vector<pair<int, int>> vals;
vector<int> L [MAX];
vector<int> R [MAX];
void solve_case(){
    conv.clear();
    pts.clear();
    cin >> n;
    vals.clear();
    vals.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i].first >> vals[i].second;
        pts.insert(vals[i].first); pts.insert(vals[i].second);
    }
    int cnt = 0;
    for(int x: pts){
        conv[x] = cnt;
        cnt++;
    }
    for(int i = 0; i < n; i++){
        vals[i].first = conv[vals[i].first];
        vals[i].second = conv[vals[i].second];
    }
    for(int i = 0; i < cnt + 3; i++){
        L[i].clear();
        R[i].clear();
        for(int j = 0; j < cnt + 3; j++){
            dp[i][j] = 0;
        }
    }
    for(auto s: vals){
        L[s.first].push_back(s.second);
        R[s.second].push_back(s.first);
    }
    for(int len = 1; len <= cnt; len++){
        for(int l = 0; l < cnt; l++){
            int r = l + len - 1;
            if(r >= cnt) continue;
            if(l != r){
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                dp[l][r] = max(dp[l][r], dp[l + 1][r - 1]);
            }
            int ok = 0;
            for(int ri: L[l]){
                if(ri < r){
                    dp[l][r] = max(dp[l][r], dp[l][ri] + dp[ri + 1][r]);
                }
                else if(ri == r) ok = 1;
            }
            for(int le: R[r]){
                if(l < le){
                    if(le) dp[l][r] = max(dp[l][r], dp[l][le - 1] + dp[le][r]);
                    else dp[l][r] = max(dp[l][r], dp[le][r]);
                }
                else if(l == le) ok = 1;
            }
            dp[l][r] += ok;
        }
    }
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        for(int j = i; j < cnt; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
    return 0;
}