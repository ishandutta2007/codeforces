#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int dp[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int mx = 0;
    int lst = -1;
    for(int i = 1; i<=N; i++){
        for(int k = 1; k>=-1; k--){
            if(arr[i]-k > lst){
                mx++;
                lst = arr[i]-k;
                break;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        int l = 1, r = i, idx = i;
        while(l <= r){
            int mid = l+r>>1;
            if(arr[mid] >= arr[i]-2){
                r = mid - 1;
                idx = mid;
            }
            else{
                l = mid + 1;
            }
        }
        dp[i] = dp[idx-1] + 1;
    }
    cout << dp[N] << " " << mx << endl;
}