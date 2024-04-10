#include <bits/stdc++.h>

using namespace std;

long long o[4][4];
long long m[4][4];
long long t[4][4];
long long MOD = 1e9+7;

void mexpo(int n){
    if(n == 1){
        return;
    }
    mexpo(n/2);
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            t[i][j] = 0;
            for(int k = 0; k<4; k++){
                t[i][j] += m[i][k] * m[k][j];
                t[i][j] %= MOD;
            }
        }
    }
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            m[i][j] = t[i][j];
        }
    }
    if(n&1){
        for(int i = 0; i<4; i++){
            for(int j= 0; j<4; j++){
                t[i][j] = 0;
                for(int k = 0; k<4; k++){
                    t[i][j] += m[i][k] * o[k][j];
                    t[i][j] %= MOD;
                }
            }
        }
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++){
                m[i][j] = t[i][j];
            }
        }
    }
}

int main(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(i != j){
                m[i][j] = o[i][j] = 1;
            }
        }
    }
    int N;
    cin >> N;
    mexpo(N);
    cout << m[0][0] << endl;
}