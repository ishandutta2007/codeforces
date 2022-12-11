#include<cstdio>
int dp[1000][10];
bool judge(int x,int d){
    for(;x;x/=10)
        if(x%10==d) return true;
    return false;
}
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<1000;j++){
            if(judge(j,i)) dp[j][i]=1;
            else
                for(int k=j-1;k>=j/2;k--)
                    if(dp[k][i]&&dp[j-k][i]){
                        dp[j][i]=1;
                        break;
                    }
        }
    }
    int d,t,q,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&q,&d);
        while(q--){
            scanf("%d",&a);
            if(a>950||dp[a][d]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}