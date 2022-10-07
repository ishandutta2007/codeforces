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
#define N 1000005
char a[N],b[N];
bool a0,b0;
int main(){
#ifndef ONLINE_JUDGE
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
#endif
    scanf("%s",a+1);
    scanf("%s",b+1);
    if(strlen(a+1)!=strlen(b+1)) return printf("NO"),0;
    For(i,1,strlen(a+1)) if(a[i]=='1'){a0=1;break;}
    For(i,1,strlen(b+1)) if(b[i]=='1'){b0=1;break;}
    return printf(a0==b0?"YES":"NO"),0;
}