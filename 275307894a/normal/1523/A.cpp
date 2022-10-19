#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,pre[1001],nex[1010];
char c[1010];
int get(){
    scanf("%d%d%s",&n,&m,c+1);
    bool flag=0;pre[0]=-1e9;nex[n+1]=1e9;
    for(int i=1;i<=n;i++)pre[i]=(c[i]=='1'?i:pre[i-1]),flag|=(c[i]=='1');
    if(!flag)return printf("%s\n",c+1),0;
    for(int i=n;i>=1;i--)nex[i]=(c[i]=='1'?i:nex[i+1]);
    for(int i=1;i<=n;i++)if(c[i]=='0'&&i-pre[i]!=nex[i]-i&&(i-pre[i]<=m||nex[i]-i<=m))c[i]='1';
    printf("%s\n",c+1);
    return 0;
}
int main(){
    int T;scanf("%d",&T);while(T--)get();
    return 0;
}