#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
bool done[45][45][45][45];
int dp[45][45][45][45];
char mp[45][45];
int h[45][45];

int solve(int tx, int ty, int bx, int by){
    //cout << tx << " " << ty << " " << bx << " " << by << "\n";
    if(tx > bx || ty > by){
        return 0;
    }
    if(done[tx][ty][bx][by]){
        return dp[tx][ty][bx][by];
    }
    //cout << "dude" << endl;
    int mn = ty;
    for(int i = ty; i<=by; i++){
        if(h[bx][i] < h[bx][mn]){
            mn = i;
        }
    }
    //cout << tx << " " << ty << " " << bx << " " << by << " " << mn << " " << h[bx][mn] << "\n";
    int ret = (min(bx-tx+1, h[bx][mn])*(mn-ty+1)*(by-mn+1));
    ret += solve(tx, ty, bx, mn-1);
    ret += solve(tx, mn+1, bx, by);
    done[tx][ty][bx][by] = 1;
    return dp[tx][ty][bx][by] = ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(mp[i][j] == '0'){
                h[i][j] = h[i-1][j] + 1;
            }
            //cout << h[i][j];
        }
        //cout << endl;
    }
    while(Q--){
        int tx, ty, bx, by;
        cin >> tx >> ty >> bx >> by;
        int ans = 0;
        for(int j = tx; j<=bx; j++){
            ans += solve(tx, ty, j, by);
        }
        cout << ans << "\n";
    }
}