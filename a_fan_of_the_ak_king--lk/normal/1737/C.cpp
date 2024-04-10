#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,M2=1004535809,M3=469762049,E=524288,N=1000005;
int t,n,k,a[N],b[N],z,x,y;
int p[2];
int cor(int x,int y){
    return (x==1||x==n)&&(y==1||y==n);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        p[0]=p[1]=0;
        z=-1;
        int u=0;
        for(int i=0;i<3;++i){
            scanf("%d %d",&a[i],&b[i]);
            ++p[(a[i]+b[i])%2];
            if(cor(a[i],b[i])){
                z=(a[i]+b[i])%2;
                u=i;
            }
        }
        for(int i=0;i<3;++i)
            if(p[(a[i]+b[i])%2]==1)
                u=i;
        scanf("%d %d",&x,&y);
        if(z==-1||p[z]==2){
            if(p[(x+y)%2]!=2&&(x-a[u])%2!=0)
                puts("NO");
            else
                puts("YES");
        }
        else
            puts(x==a[u]||y==b[u]?"YES":"NO");
    }
}