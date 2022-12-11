#include <bits/stdc++.h>

using namespace std;

long long arr[100];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr[0] = arr[1] = 1;
    for(int i = 2; i<100; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    long long N;
    cin >> N;
    long long ans = 0;
    for(int i = 1; i<100; i++){
        arr[i] += arr[i-1];
        if(arr[i-1] >= N){
            break;
        }
        ans = i;
    }
    cout << ans << endl;
}