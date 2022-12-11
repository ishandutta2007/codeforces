#include <bits/stdc++.h>

using namespace std;

long long N, K, L, MOD, P, A, B;
long long mat[2][2][4];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

void mult(int a, int b, int c){
    for(int i = 0; i<2; i++){
        for(int j= 0; j<2; j++){
            mat[i][j][c] = 0;
            for(int k = 0; k<2; k++){
                mat[i][j][c] = add(mat[i][j][c], mult(mat[i][k][a], mat[k][j][b]));
            }
        }
    }
}

void qikpow(long long n){
    if(!n){
        return;
    }
    qikpow(n/2);
    mult(0, 0, 1);
    if(n&1){
        mult(1, 2, 0);
    }
    else{
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2;j++){
                swap(mat[i][j][0], mat[i][j][1]);
            }
        }
    }
}

long long qikpow(long long n, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(n, e/2);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, n);
    }
    return ret;
}

int main(){
    cin >> N >> K >> L >> MOD;
    mat[0][0][0] = mat[1][1][0] = mat[0][1][2] = mat[1][1][2] = mat[1][0][2] = 1;
    qikpow(N+1);
    P = qikpow(2, N);
    A = add(mat[0][0][0], mat[0][1][0]);
    B = P - A;
    if(B < 0){
        B += MOD;
    }
    long long ans = 1;
    for(int i = 0; i<L; i++){
        if((1LL<<i)&K){
            ans = mult(B, ans);
        }
        else{
            ans = mult(A, ans);
        }
    }
    if(L != 64 && (1ULL<<L)-1 < K){
        ans = 0;
    }
    cout << ans%MOD << endl;
}