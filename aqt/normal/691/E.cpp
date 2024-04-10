#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[105];
long long K;
long long MOD = 1e9+7;
long long o[105][105];
long long m[105][105];
long long t[105][105];

void solve(long long e){
    if(e == 1){
        for(int i = 1; i<=N; i++){
            for(int j= 1; j<=N; j++){
                m[i][j] = o[i][j];
            }
        }
        return;
    }
    solve(e/2);
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            t[i][j] = 0;
            for(int k = 1; k<=N; k++){
                t[i][j] += m[i][k] * m[k][j];
                t[i][j] %= MOD;
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            m[i][j] = t[i][j];
        }
    }
    if(e&1){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                t[i][j] = 0;
                for(int k = 1; k<=N; k++){
                    t[i][j] += m[i][k] * o[k][j];
                    t[i][j] %= MOD;
                }
            }
        }
        for(int i = 1; i<=N; i++){
            for(int j= 1; j<=N; j++){
                m[i][j] = t[i][j];
            }
        }
    }
}

int main(){
    cin >> N >> K;
    if(K == 1){
        cout << N << endl;
        return 0;
    }
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            if(__builtin_popcountll(arr[i]^arr[j])%3 == 0){
                o[i][j] = 1;
            }
        }
    }
    solve(K-1);
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            ans += m[i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}