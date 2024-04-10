#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long arr[20];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    long long sum = 0;
    long long ans = 0;
    fill(arr+1, arr+M, LLONG_MIN/4);
    arr[0] = -K;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        sum += n;
        if(arr[i%M] < -sum){
            arr[i%M] = -sum;
        }
        for(int j = 0; j<M; j++){
            ans = max(ans, sum+arr[j]);
        }
        arr[i%M] -= K;
    }
    cout << ans << endl;
}