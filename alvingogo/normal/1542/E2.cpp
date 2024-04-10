#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int mod;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int main(){
    AquA;
    int n;
    cin >> n >> mod;
    vector<int> dp(1,1);
    int ans=0;
    for(int i=1;i<n;i++){
        vector<int> sum=dp;
        for(int j=1;j<dp.size();j++){
            add(sum[j],sum[j-1]);
        }
        int nw=1;
        for(int j=n;j>i+1;j--){
            nw=mul(nw,j);
        }
        for(int j=1;j<=i;j++){
            add(ans,mul(mul(nw,i+1-j),(i*(i-1)/2-j-1<0)?0:sum[i*(i-1)/2-j-1]));
        } 
        vector<int> fn((i+1)*i+1);
        int a=(i+1)*i/2,b=(i-1)*(i)/2;
        int m=dp.size();
        assert(2*b+1==m);
        fn[0]=dp[0];
        for(int j=-(i+1)*i/2+1;j<=(i+1)*i/2;j++){
            add(fn[j+a],fn[j+a-1]);
            if(j+b-(i+1)-1>=0){
                add(fn[j+a],sum[j+b-(i+1)-1]);
            }
            if(j+b+i>=0){
                add(fn[j+a],sum[min(m-1,j+b+i)]);
            }
            if(j+b-1>=0){
                add(fn[j+a],-sum[min(m-1,j+b-1)]);
                add(fn[j+a],-sum[min(m-1,j+b-1)]);
            }
        }
        dp=fn;
    }
    cout << ans << "\n";
    return 0;
}