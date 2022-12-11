#include <bits/stdc++.h>

using namespace std;

int arr[505][505];
bool sieve[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    sieve[1] = 1;
    for(int i = 2; i<=200000; i++){
        for(int j = i*2; j<=200000; j+=i){
            sieve[j] = 1;
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            int n;
            cin >> n;
            while(sieve[n]){
                arr[i][j]++;
                n++;
            }
        }
    }
    int mini = INT_MAX/2;
    for(int i = 1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=M; j++){
            cnt += arr[i][j];
        }
        mini = min(mini, cnt);
    }
    for(int j = 1; j<=M; j++){
        int cnt = 0;
        for(int i = 1; i<=N; i++){
            cnt += arr[i][j];
        }
        mini = min(mini, cnt);
    }
    cout << mini << endl;
}