#include <iostream>
#include <algorithm>

using namespace std;

long long dp[100000+10];
long long cnt[100000+10];
int n,ai;

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>ai;
        cnt[ai]++;
    }
    dp[1]=cnt[1];
    for (long long i=2; i<=100000; i++){
        dp[i]=max(cnt[i]*i+dp[i-2],dp[i-1]);
    }
    cout<<dp[100000]<<endl;
    return 0;
}