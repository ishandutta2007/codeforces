#include <bits/stdc++.h>

using namespace std;

long long N, X;
long long sum[300005], suf[300005], pre[300005], arr[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> X;
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        sum[i] = arr[i] + sum[i-1];
    }
    long long tot = 0;
    for(int i= 1; i<=N; i++){
        tot += arr[i];
        if(tot < 0){
            tot = 0;
        }
        pre[i] = tot;
        ans = max(ans, tot);
    }
    tot = 0;
    for(int i= N; i>0; i--){
        tot += arr[i];
        if(tot < 0){
            tot = 0;
        }
        suf[i] = tot;
        ans = max(ans, suf[i]);
    }
    long long mini = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, X*sum[i]+suf[i+1]-mini);
        mini = min(mini, X*sum[i]-pre[i]);
    }
    cout << ans << endl;
}