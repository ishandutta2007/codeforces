#include <bits/stdc++.h>

using namespace std;

int arr[5000005];

int main(){
    int N, C, P, K;
    cin >> N >> C >> P >> K;
    arr[1] = P;
    int maxi = max(P, N-P);
    for(int i = 2; i<=K; i++){
        if(i%2){
            arr[i] = 2*P;
            maxi = max(maxi, 2*P);
        }
        else{
            arr[i] = 2*(N-P);
            maxi = max(maxi, 2*(N-P));
        }
    }
    arr[K+1] = (K%2 ? N-P : P);
    if(maxi > C){
        cout << -1 << endl;
        return 0;
    }
    long long sum = 0;
    int cnt = 0;
    for(int i =1; i<=K+1; i++){
        if(sum + arr[i] > C){
            cnt++;
            sum = 0;
        }
        sum += arr[i];
    }
    cout << cnt << endl;
}