#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N, greater<int>());
    int l = 1, r = 200000, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        long long tot = 0;
        for(int i = 0; i<N; i++){
            tot += max(0, arr[i]-i/mid);
        }
        if(tot < M ){
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;
}