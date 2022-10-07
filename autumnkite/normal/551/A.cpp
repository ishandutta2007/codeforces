#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#define LL long long
#define For(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i<=i_E;++i)
#define Fod(i,a,b) for(register int i=(int)(a),i_E=(int)(b);i>=i_E;--i)
#define cross(i,a) for(register int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL Abs(LL a){return a>0?a:-a;}
char buf[5000000],*p1=buf,*p2=buf;
inline char GetChar(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,5000000,stdin),p1==p2)?EOF:*p1++;
}
#define CH ch=getchar()
inline LL read(){
    LL x=0;int f=1,ch;
    for(CH;!isdigit(ch)&&ch!='-'&&ch!=EOF;CH);
    if(ch=='-') f=-1,CH;
    for(;isdigit(ch);CH) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
inline void write(LL x){
    if(x<10) putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
#define N 2005
int n,a[N];
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=read();
    For(i,1,n) a[i]=read();
    For(i,1,n){
        int s=1;
        For(j,1,n) if(a[j]>a[i]) s++;
        printf("%d ",s);
    }
}