#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];

int main(){
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int l = 1, r = N/2, ans = 0;
    while(l <= r){
        int mid = l+r>>1;
        bool works = 1;
        for(int i = 1, j = N-mid+1; j<=N; i++, j++){
            if(arr[j]-arr[i] < K){
                works = 0;
            }
        }
        if(works){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}