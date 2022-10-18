#include <cstdio>
 
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
 
template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()
 
char str[1010];
 
int main() {
    int t=R();
    while(t--) {
        int n=R(),x=n+1,y=-1,ans;
        scanf("%s",str+1);
        for(int i=1;i<=n;i++)
            if(str[i]=='1')x=min(x,i),y=max(y,i);
        if(x==n+1&&y==-1)printf("%d\n",n);
        // else if(x==1||y==n)printf("%d\n",n*2);
        else {
            if(n-x+1>y)ans=n-x+1;
            else ans=y;
            ans*=2;
            printf("%d\n",ans);
        }
    }
    return 0;
}