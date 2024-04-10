#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int ans = 0;
    for(int l = 1, r = 1; r<=N; r++){
        while(arr[l] + 5 < arr[r]){
            l++;
        }
        ans = max(r-l+1, ans);
    }
    cout << ans << endl;
}