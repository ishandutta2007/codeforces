#include<cstdio>
int t,n,m;
int work(int x,int y,int k){
    if(k==0){
        if(x&&!y) return 0;
        if(y&&!x) return 2;
        if(!x&&!y) return 1;
        if(x&&y) return 2;
    }
    if(((x>>k)&1)&&((y>>k)&1)){
        int ans=work(x&((1<<k)-1),y&((1<<k)-1),k-1);
        if(ans>=(1<<k)) return 1<<(k+1);
        else return ans;
    }
    if(((x>>k)&1)==((y>>k)&1))
        return work(x&((1<<k)-1),y&((1<<k)-1),k-1);
    if(((x>>k)&1)&&!((y>>k)&1)) return 0;
    int ans=work(x&((1<<k)-1),y&((1<<k)-1),k-1);
    return (1<<k)+ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
    // for(n=0;n<=10;n++)
    //     for(m=0;m<=10;m++){
        scanf("%d%d",&n,&m);
        if(n>m) puts("0");
        else
            printf("%d\n",work(n,m,30));
            // if((n^(ans+flag))<=m) printf("%d %d %d\n",n,m,ans+flag);
    }
    return 0;
}