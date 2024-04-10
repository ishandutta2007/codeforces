#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=8000005;
int dp[N],m,n;
inline int lb(int x){return x&-x;}
inline void add(int x,int y){
    dp[x]+=y;
    if(dp[x]>m) dp[x]-=m;
    else if(dp[x]<0) dp[x]+=m;
}
inline void add(int l,int r,int y){
    add(l,y); add(r+1,-y);
}
inline int query(int x){
    return dp[x];
}
int main(){
    scanf("%d%d",&n,&m); 
    int sum=1,now,val=0;
    long long cnt;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i])%m;
        val=(sum+query(i))%m;
        if(i==1){
            add(2,2,1);
            for(int j=3;j<=n;j+=2)
                add(j,j+1,val*((j+1ll)/2)%m);
            continue;
        }
        now=i*2; cnt=0;
        while(now<=n){
            for(int j=(cnt==0)?2:0;j<i&&now<=n;j++){
                if(j==0){
                    add(now,now+2*i-1,cnt*val%m);
                    now=now+2*i;
                }
                else{
                    add(now,now+j-1,(cnt+1)*val%m);
                    now+=j;
                    add(now,now+i-j-1,cnt*val%m);
                    now+=i-j;
                }
            }
            ++cnt;
        }
        sum=(sum+val)%m;
    }
    printf("%d\n",val);
    // scanf("%d",&n);
    // for(int i=2;i<=100;i++){
    //     int now=0;
    //     for(int j=2;j<=i;j++)
    //         if(i/j==n) now++;
    //     printf("%d:%d\n",i,now);
    // }
    return 0;
}