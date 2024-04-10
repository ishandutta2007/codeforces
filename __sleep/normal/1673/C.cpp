#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=40005,P=1000000007;
int t,n,dp[N];
inline bool judge(int x){
    int tmp[5]={0},cnt=0;
    for(;x;x/=10)
        tmp[cnt++]=x%10;
    for(int i=0;i<cnt/2;i++)
        if(tmp[i]!=tmp[cnt-i-1]) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    vector<int> rev;
    dp[0]=1;
    for(int i=1;i<N;i++){
        if(judge(i))
            for(int j=i;j<N;++j)
                dp[j]=(dp[j-i]+dp[j])%P;
    }
    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}