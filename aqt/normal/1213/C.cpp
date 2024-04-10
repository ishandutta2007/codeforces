#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>> T;
    while(T--){
        long long N, M;
        cin >> N >> M;
        fill(arr, arr+10, 0);
        int cnt = 1;
        long long idx = M%10;
        long long sum = 0;
        while(idx){
            sum += idx;
            arr[idx] = cnt++;
            idx += M;
            idx %= 10;
        }
        long long ans = 0;
        long long L = N/M;
        ans += L/cnt*sum;
        L%=cnt;
        for(int d = 0; d<10; d++){
            if(arr[d] && arr[d] <= L){
                ans += d;
            }
        }
        cout << ans << "\n";
    }
}