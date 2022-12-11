#include <bits/stdc++.h>

using namespace std;

int N, K;
int grid[505][505];
int fre[300000];
int sz[300000], cnt = 0;
int m[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y){
    grid[x][y] = cnt;
    sz[cnt]++;
    for(int k = 0; k<4; k++){
        if(grid[x+m[k][0]][y+m[k][1]] == 0){
            dfs(x+m[k][0], y+m[k][1]);
        }
    }
}

int upd(int i, int j, int v){
    fre[grid[i][j]] += v;
    if(fre[grid[i][j]] == 1 && v == 1){
        return sz[grid[i][j]];
    }
    else if(fre[grid[i][j]] == 0 && v == -1){
        return -sz[grid[i][j]];
    }
    else{
        return 0;
    }
}

int main(){
    cin >> N >> K;
    fill(grid[0], grid[0] + N + 2, -1);
    fill(grid[N+1], grid[N+1] + N + 2, -1);
    for(int i = 1; i<=N; i++){
        grid[i][0] = grid[i][N+1] = -1;
        string s;
        cin >> s;
        for(int j = 1; j<=N; j++){
            grid[i][j] = ((s[j-1] == '.') ? 0 : -1);
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(!grid[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    int ans = 0;
    for(int i = K; i<=N; i++){
        int in = 0, sd = 0;
        for(int x = i-K+1; x<=i; x++){
            for(int y = 0; y<K; y++){
                if(grid[x][y] != -1){
                    in++;
                    sd += upd(x, y, 1);
                }
            }
        }
        for(int j = K; j<=N; j++){
            for(int k = i-K+1; k<=i; k++){
                if(grid[k][j-K] != -1){
                    in--;
                    sd += upd(k, j-K, -1);
                }
                if(grid[k][j] != -1){
                    in++;
                    sd += upd(k, j, 1);
                }
            }
            for(int k = j-K+1; k<=j; k++){
                sd += upd(i+1, k, 1);
                sd += upd(i-K, k, 1);
            }
            for(int k = i-K+1; k<=i; k++){
                sd += upd(k, j+1, 1);
                sd += upd(k, j-K, 1);
            }
            ans = max(ans, K*K - in + sd);
            for(int k = j-K+1; k<=j; k++){
                sd += upd(i+1, k, -1);
                sd += upd(i-K, k, -1);
            }
            for(int k = i-K+1; k<=i; k++){
                sd += upd(k, j+1, -1);
                sd += upd(k, j-K, -1);
            }
        }
        fill(fre, fre+cnt+1, 0);
    }
    cout << ans << endl;
}