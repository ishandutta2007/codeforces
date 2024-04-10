#include <bits/stdc++.h>

using namespace std;

long long arr[1001];
long long N, K;

int main(){
    cin >> N >> K;
    for(int i = 0; i<K; i++){
        arr[(i*i)%K] += N/K;
    }
    for(int i = 1; i<=N%K; i++){
        arr[(i*i)%K]++;
    }
    long long ans = arr[0]*arr[0];
    for(int i = 1; i<K; i++){
        ans += arr[i]*arr[K-i];
    }
    cout << ans;
}