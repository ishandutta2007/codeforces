#include <bits/stdc++.h>

using namespace std;

int arr[101];
int N;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = i; j<=N; j++){
            ans = max(ans, j-i+1-(arr[j]-arr[i-1])+arr[i-1]+arr[N]-arr[j]);
        }
    }
    cout << ans << endl;
}