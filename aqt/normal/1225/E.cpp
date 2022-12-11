#include <bits/stdc++.h>

using namespace std;

int N, M, MOD = 1e9+7;
int dp[2][2005][2005]; //next move 0 = hor, 1 = ver
int arr[2005][2005];
int precol[2005][2005], prerow[2005][2005];

int add(int a, int b){
    return (a+b)%MOD;
}

int sub(int a, int b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    if(N == 1 && M == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            char c;
            cin >> c;
            arr[i][j] = (c == 'R');
            precol[i][j] = prerow[i][j] = arr[i][j];
            precol[i][j] += precol[i-1][j];
            prerow[i][j] += prerow[i][j-1];
        }
    }
    int tar = prerow[1][M];
    for(int j = 1; j<=M-tar; j++){
        dp[1][1][j] = 1;
    }
    tar = precol[N][1];
    for(int i = 1; i<=N-tar; i++){
        dp[0][i][1] = 1;
    }
    for(int i = 2; i<=N; i++){
        for(int j = 2; j<=M; j++){
            int l = 1, r = i, idx = i+1;
            while(l <= r){
                int mid = l+r>>1;
                if(precol[N][j]-precol[mid-1][j] >= N-i+1){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                    idx = mid;
                }
            }
            if(idx > 1){
                idx--;
            }
            //cout << "row: " << idx << endl;
            dp[0][i][j] = sub(dp[1][i-1][j], dp[1][idx-1][j]);
            l = 1, r = j, idx = j+1;
            while(l <= r){
                int mid = l + r >> 1;
                if(prerow[i][M]-prerow[i][mid-1] >= M-j+1){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                    idx = mid;
                }
            }
            if(idx > 1){
                idx--;
            }
            //cout << "col: " << idx << endl;
            dp[1][i][j] = sub(dp[0][i][j-1], dp[0][i][idx-1]);
            //cout << i << " " << j << " " << dp[0][i][j] << " " << dp[1][i][j] << endl;
            dp[0][i][j] = add(dp[0][i][j], dp[0][i][j-1]);
            dp[1][i][j] = add(dp[1][i][j], dp[1][i-1][j]);
            //cout << i << " " << j << " " << dp[0][i][j] << " " << dp[1][i][j] << endl;
        }
    }
    cout << add(sub(dp[0][N][M], dp[0][N][M-1]), sub(dp[1][N][M], dp[1][N-1][M])) << endl;
}