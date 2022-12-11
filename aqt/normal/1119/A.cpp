#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005];

int main(){
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i= 1; i<=N; i++){
        if(arr[i] != arr[N]){
            ans = max(ans, abs(N-i));
            break;
        }
    }
    int idx = N;
    while(arr[idx] == arr[N]){
        idx--;
    }
    for(int i = 1; i<=N; i++){
        if(arr[i] != arr[idx]){
            ans = max(ans, abs(idx-i));
        }
    }
    cout << ans << endl;
}