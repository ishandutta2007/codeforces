#include <cstdio>
 
#define cmin(a,b) ((a)<(b)?(a):(b))
#define cmax(a,b) ((a)>(b)?(a):(b))
 
template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()
 
int main() {
    int a=R(),b=R(),c=R(),d=R(),e=R(),f=R(),ans=0;
    for(int i=0;i<=cmin(a,d);i++) {
        int x=i*e+f*cmin(d-i,cmin(b,c));
        ans=cmax(ans,x);
    }
    return !printf("%d\n",ans);
}