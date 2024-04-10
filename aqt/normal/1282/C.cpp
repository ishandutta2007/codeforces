#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long N, M, a, b;
        cin >> N >> M >> a >> b;
        long long cnta = 0, cntb = 0;
        for(int i = 1; i<=N; i++){
            cin >> arr[i].second;
            if(arr[i].second){
                cntb++;
            }
            else{
                cnta++;
            }
        }
        for(int i= 1; i<=N; i++){
            cin >> arr[i].first;
        }
        N++;
        arr[N].first = M+1, arr[N].second = 1;
        cntb++;
        sort(arr+1, arr+1+N);
        long long ans = 0;
        long long t = 0, crnt = 0;
        for(int i = 1; i<=N; i++){
            t = arr[i].first;
            if(crnt + cnta*a < t){
                long long temp = (t-1 - crnt - cnta*a)/b;
                temp = min(temp, cntb*1LL);
                ans = max(ans, temp+cnta+i-1);
            }
            else if(crnt < t){
                long long temp = (t-1-crnt)/a;
                temp = min(temp, cnta*1LL);
                ans = max(ans, temp+i-1);
            }
            if(arr[i].second){
                cntb--;
                crnt += b;
            }
            else{
                cnta--;
                crnt += a;
            }
        }
        cout << min(ans, 1LL*(N-1)) << "\n";
    }
}