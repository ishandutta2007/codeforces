#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int K, N, A, B;
        cin >> K >> N >> A >> B;
        K--;
        int l = 0, r = min(N, K/A), ans = -1;
        while(l <= r){
            int mid = l+r>>1;
            if(mid+(K-mid*A)/B >= N){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout<< ans << "\n";
    }
}