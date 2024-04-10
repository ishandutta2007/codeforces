#include<cstdio>
using namespace std;
const int N=1e3+10;
int T,n,a[N],p[N];
int dfs(int now,int cur){
    p[now]=a[cur];
    for(int i=1;i<now;i++)printf("%d.",p[i]);if(now)printf("%d\n",p[now]);
    int cnt=1;
    for(int j=cur+1;j<=n+1;){
        if(a[j]==cnt++)j=dfs(now+1,j);
        else return j;
    }
}
int get(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(0,0);
    return 0;
}
int main(){
    // freopen("_.in","r",stdin);
    scanf("%d",&T);while(T--)get();
    return 0;
}