#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define LL long long
#define For(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i<=i_E;++i)
#define Fod(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i>=i_E;--i)
#define cross(i,a) for(register int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL Abs(LL a){return a>=0?a:-a;}
#define IN_MAX 1000000
inline char GetChar(){
    static char buf[IN_MAX],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,IN_MAX,stdin),p1==p2)?EOF:*p1++;
}
#define CH ch=getchar()
inline LL read(){
    LL x=0;int f=1,ch;
    for(CH;!isdigit(ch)&&ch!='-'&&ch!=EOF;CH);
    if(ch=='-') f=-1,CH;
    for(;isdigit(ch);CH) x=(x<<3)+(x<<1)+ch-48;
    return x*f;
}
inline void write(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x<10) putchar(x+48);
    else write(x/10),putchar(x%10+48);
}
int n,m,a[20],b[20],ans=100;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    for(n=read(),m=9;n;n/=10,--m) a[m]=n%10;
    while(!b[m]){
        int i=9;
        for(;b[i];--i) b[i]=0;
        b[i]=1;
        for(i=m+1;b[i];++i);
        if(!a[i]) continue;
        int s=0,s1=0;
        For(i,m+1,9) s=(b[i]?s:s*10+a[i]),s1+=b[i];
        double x=sqrt(s);
        if(x==int(x)) ans=Min(s1,ans);
    }
    return printf("%d",ans<100?ans:-1),0;
}