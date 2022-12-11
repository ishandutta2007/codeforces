#include<cstdio>
const int N=300005;
char s[N];
int sum[N];
int main(){
    int t,n,q,l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%s",&n,&q,s+1);
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+(i&1?1:-1)*(s[i]=='+'?1:-1);
        while(q--){
            scanf("%d%d",&l,&r);
            if((sum[r]-sum[l-1])&1) puts("1");
            else if(sum[r]-sum[l-1]==0) puts("0");
            else puts("2");
        }
    }
    return 0;
}