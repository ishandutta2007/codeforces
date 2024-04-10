#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long arr[200005];

bool chk(long long x){
    long long ans = 0;
    for(int i = (N+1)/2; i<=N; i++){
        ans += max(0LL, x-arr[i]);
    }
    return ans <= K;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    long long l = 1, r = 2000000000, ans = 0;
    while(l <= r){
        long long mid = l+r>>1;
        if(chk(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}