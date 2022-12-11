#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >>K;
    K = 2*K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N+1);
    int cnt = 0;
    for(int i= 1; i<=N; i++){
        while(arr[i] > K){
            cnt++;
            K *= 2;
        }
        K = max(K, arr[i]*2);
    }
    cout << cnt << endl;
}