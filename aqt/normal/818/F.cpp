#include <bits/stdc++.h>

using namespace std;

int T, N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        long long l = 1, r = N, cnt = 1;
        while(l <= r){
            long long mid = l+r>>1;
            //cout << mid << endl;
            if(mid*(mid-1)/2 <= N-1-mid+1){
                cnt = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        long long ans = cnt*(cnt-1)/2+N-1-cnt+1;
        if(cnt*(cnt-1)/2+2 <= N-1-cnt+1-1){
            ans += N-1-cnt+1-1-cnt*(cnt-1)/2-1;
        }
        cout << ans << "\n";
    }
}