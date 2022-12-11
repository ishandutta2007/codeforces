#include <bits/stdc++.h>

using namespace std;

int N, M = 2000000;
int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int ans = 0;
    for(int i = 1; i<=N; i++){
        if(arr[i] == arr[i-1]){
            continue;
        }
        bool b = 1;
        for(int j = 2*arr[i]-1; j<=M && b; j+=arr[i]){
            int l = i+1, r = N;
            while(l <= r){
                int mid = l+r>>1;
                if(arr[mid] <= j){
                    if(l == N){
                        b = 0;
                    }
                    ans = max(ans, arr[mid]%arr[i]);
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
    }
    cout << ans << endl;
}