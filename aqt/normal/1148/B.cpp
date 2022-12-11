#include <bits/stdc++.h>

using namespace std;

int N, M, K, Ta, Tb;
int arr[200005], brr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Ta >> Tb>> K ;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=M; i++){
        cin >> brr[i];
    }
    if(N <= K){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0, j = 1; i<=K; i++){
        while(brr[j] < arr[i+1] + Ta){
            j++;
        }
        if(j + K - i > M){
            ans = -1;
            break;
        }
        ans = max(ans, brr[j+K-i] + Tb);
    }
    cout << ans << endl;
}