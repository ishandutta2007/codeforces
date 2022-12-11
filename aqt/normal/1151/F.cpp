#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long matrix[10][105][105];
long long MOD = 1e9+7;
int arr[105];

void mult(int u, int v, int p){
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            matrix[p][i][j] = 0;
            for(int k = 0; k<=N; k++){
                matrix[p][i][j] += matrix[u][i][k] * matrix[v][k][j];
                matrix[p][i][j] %= MOD;
            }
        }
    }
}

void cop(int f, int t){
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            matrix[t][i][j] = matrix[f][i][j];
        }
    }
}

void mpow(long long e){
    if(!e){
        for(int i = 0; i<=N; i++){
            matrix[1][i][i] = 1;
        }
        return;
    }
    mpow(e/2);
    mult(1, 1, 2);
    cop(2, 1);
    if(e&1){
        mult(1, 0, 2);
        cop(2, 1);
    }
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = ret*ret%MOD;
    if(e&1){
        ret *= b;
        ret %= MOD;
    }
    return ret;
}

int main(){
    cin>> N >> K;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        cnt += !arr[i];
    }
    int s = 0;
    for(int i = 1; i<=cnt; i++){
        s += !arr[i];
    }
    long long inv = qikpow(N*(N-1)/2, MOD-2);
    for(int i = 0; i<=cnt; i++){
        if(cnt-i > N-cnt){
            continue;
        }
        long long tot = N*(N-1)/2;
        if(i-1 >= 0){
            matrix[0][i][i-1] = max(0LL, (inv*(N-cnt-(cnt-i))*i)%MOD);
            tot -= max(0, (N-cnt-(cnt-i))*i);
        }
        if(i+1 <= cnt){
            matrix[0][i][i+1] = max(0LL, (inv*(cnt-i)*(cnt-i))%MOD);
            tot -= max(0, (cnt-i)*(cnt-i));
        }
        matrix[0][i][i] = (inv*tot)%MOD;
    }
    mpow(K);
    matrix[3][s][s] = 1;
    mult(3, 1, 2);
    cout << matrix[2][s][cnt] << endl;
}