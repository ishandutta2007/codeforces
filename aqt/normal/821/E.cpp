#include <bits/stdc++.h>

using namespace std;

int N, M = 16;
long long K;
long long m[17][17][20];
long long MOD = 1e9+7;

long long mult(int p, int a, int b){
    for(int i= 0; i<=M; i++){
        for(int j= 0; j<=M; j++){
            m[i][j][p] = 0;
            for(int k = 0; k<=M; k++){
                m[i][j][p] += m[i][k][a] * m[k][j][b];
                m[i][j][p] %= MOD;
            }
        }
    }
}

void cop(int p, int q){
    for(int i= 0; i<=M; i++){
        for(int j= 0; j<=M;j ++){
            m[i][j][p] = m[i][j][q];
        }
    }
}

void solve(long long n, int h){
    if(!n){
        for(int i = 0; i<=M; i++){
            for(int j= 0; j<=M; j++){
                if(i == j){
                    m[i][j][19] = 1;
                }
                else{
                    m[i][j][19] = 0;
                }
            }
        }
        return;
    }
    solve(n/2, h);
    mult(18, 19, 19);
    cop(19, 18);
    if(n&1){
        mult(18, 19, h);
        cop(19, 18);
    }
}

int main(){
    for(int t = 0; t<=16; t++){
        m[t][t][17] = 1;
        for(int i = 0; i<=t; i++){
            for(int j = 0; j<=t; j++){
                if(abs(i-j) <= 1){
                    m[i][j][t] = 1;
                }
            }
        }
    }
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        long long a, b, h;
        cin >> a >> b >> h;
        if(i == N){
            b = K;
        }
        solve(b-a, h);
        mult(18, 17, 19);
        cop(17, 18);
    }
    cout << m[0][0][17] << endl;
}