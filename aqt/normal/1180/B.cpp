#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int maxi = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(arr[i] >= 0){
            arr[i] = -arr[i]-1;
        }
        maxi = min(maxi, arr[i]);
    }
    if(N&1){
        for(int i = 1; i<=N; i++){
            if(arr[i] == maxi){
                arr[i] = -arr[i]-1;
                break;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cout << arr[i] << " ";
    }
}