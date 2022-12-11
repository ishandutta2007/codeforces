#include <bits/stdc++.h>

using namespace std;

int fre[101];
int N;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        int K;
        cin >> K;
        for(int j = 1; j<=K; j++){
            int n;
            cin >> n;
            fre[n]++;
        }
    }
    for(int i = 1; i<=100; i++){
        if(fre[i] == N){
            cout << i << " ";
        }
    }
}