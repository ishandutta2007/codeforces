#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[55][55];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        for(int j = 1; j<=M;j ++){
            cin >> arr[i][j];
        }
    }
    long long cnt = 0;
    for(int k = 1; k<=N; k++){
        long long v = 0;
        for(int i = 1; i<=M; i++){
            v += arr[k][i];
        }
        cnt += (1LL<<v) + (1LL<<(M-v)) - 2;
    }
    for(int k = 1; k<=M; k++){
        long long v = 0;
        for(int i = 1; i<=N; i++){
            v += arr[i][k];
        }
        cnt += (1LL<<v) + (1LL<<(N-v)) - 2;
    }
    cnt -= N*M;
    cout << cnt << endl;
}