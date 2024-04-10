#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];

int main(){
    cin >> N;
    int mini = 1000;
    int ans = 0, tot = 0;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        mini = min(arr[i], mini);
        ans += arr[i];
        tot += arr[i];
    }
    for(int i= 1; i<=N; i++){
        for(int j= 1; j<=arr[i]; j++){
            if(arr[i]%j == 0){
                ans = min(ans, arr[i]/j + j*mini + tot - mini - arr[i]);
            }
        }
    }
    cout << ans << endl;
}