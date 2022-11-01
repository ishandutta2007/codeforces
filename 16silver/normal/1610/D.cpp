#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
const long long MOD=1'000'000'007LL;
int cnt[30];
long long ans;
long long f(long long n){
    if(n==0) return 1LL;
    if(n&1) return 2*f(n-1)%MOD;
    long long h=f(n/2);
    return h*h%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<30;j++){
            if(x&(1<<j)){
                cnt[j]++;
                break;
            }
        }
    }
    ans=(f(n)+MOD-1)%MOD;
    int tmp=n-cnt[0];
    for(int i=1;i<30;i++){
        if(cnt[i]==0) continue;
        ans=(ans+MOD-f(tmp-1))%MOD;
        tmp-=cnt[i];
    }
    cout << ans;
}