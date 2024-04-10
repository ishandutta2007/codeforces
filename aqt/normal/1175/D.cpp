#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[300005];;

int main(){
    cin >> N >> K;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    long long ans = arr[N]*K;
    sort(arr+1, arr+N);
    for(int i = 1; i<K; i++){
        ans -= arr[i];
    }
    cout << ans << endl;
}