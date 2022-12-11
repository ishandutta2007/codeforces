#include<cstdio>
#include<algorithm>
const int N=100005;
int a[N],n,t;
char s[N],g[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s);
        for(int i=0;i<=n;i++)
            g[i]=s[i];
        std::sort(g,g+n);
        int ans=0;
        for(int i=0;i<n;i++)
            if(s[i]!=g[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}