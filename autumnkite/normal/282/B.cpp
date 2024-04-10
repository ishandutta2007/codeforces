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
struct node{
    int id,x,y;
    bool operator <(const node&b)const{return x<b.x;}
}a[N];
int n,s1=0,s2=0;
char p[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
#endif
    n=read();
    For(i,1,n) a[i].id=i,a[i].x=read(),a[i].y=read();
    sort(a+1,a+1+n);
    int i=1,j=n;
    while(i<=j) if(Abs(s1+a[i].x-s2)<Abs(s1-s2-a[j].y)) p[a[i].id]='A',s1+=a[i++].x;else p[a[j].id]='G',s2+=a[j--].y;
    if(Abs(s1-s2)>500) printf("-1");
    else For(i,1,n) putchar(p[i]);
    return 0;
}