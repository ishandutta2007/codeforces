#include <bits/stdc++.h>

using namespace std;

long long N, H;

int main(){
    cin >> N >> H;
    long long l = 1, r = 2000000000, ans = LLONG_MAX;
    while(l <= r){
        long long mid = l+r>>1;
        if(mid <= H){
            if(N - mid*(mid+1)/2 <= 0){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else if(N - mid*(mid+1)/2 <= mid){
                ans = min(ans, mid + 1);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            long long v = (mid+H)*(mid-H+1)/2 + mid*(mid-1)/2;
            if(N - v <= 0){
                ans = min(ans, mid + mid - H);
                r = mid - 1;
            }
            else if(N - v <= mid){
                ans = min(ans, mid + mid - H + 1);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    }
    cout << ans << endl;
}