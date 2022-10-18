
#include <cstdio>
#include <bitset>
#include <cstdlib>
 
#define cmin(a,b) ((a)<(b)?(a):(b))
#define cmax(a,b) ((a)>(b)?(a):(b))
 
using std::bitset;
 
template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()
 
bitset<210>b;
int n,cnt,ans[610];
char str[210];
 
int main() {
    n=R();scanf("%s",str+1);
    for(int i=1;i<=n;i++)
        b[i]=str[i]=='B'?1:0;
    int f=b.count();
    for(int i=1;i<n;i++) {
        if(b[n]==0) {
            for(int j=1;j<=n;j++)
                if(b[i])ans[++cnt]=i,b.flip(i),b.flip(i+1);
        } else {
            for(int j=1;j<=n;j++)
                if(b[i]==0)ans[++cnt]=i,b.flip(i),b.flip(i+1);
        }
    }
    if(n%2==0&&f%2)return !printf("-1\n");
    if(b.none()||b.all()) {
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
        return 0;
    }
    for(int i=1;i<n;i++) {
        if(b[n]==0) {
            for(int j=1;j<=n;j++)
                if(b[i])ans[++cnt]=i,b.flip(i),b.flip(i+1);
        } else {
            for(int j=1;j<=n;j++)
                if(b[i]==0)ans[++cnt]=i,b.flip(i),b.flip(i+1);
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
    return 0;
}