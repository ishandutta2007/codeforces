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
#define N 100005
char a[N],b[N],c[N];
int la,lb,lc,sa[26],sb[26],sc[26];
int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    scanf("%s%s%s",a+1,b+1,c+1);
    la=strlen(a+1),lb=strlen(b+1),lc=strlen(c+1);
    For(i,1,la) sa[a[i]-97]++;
    For(i,1,lb) sb[b[i]-97]++;
    For(i,1,lc) sc[c[i]-97]++;
    int sumb=2147483647,sumc=2147483647,maxb=0,maxc=0;
    For(i,0,25) if(sb[i]) sumb=Min(sumb,sa[i]/sb[i]);
    For(i,0,sumb){
        For(j,0,25) if(sc[j]) sumc=Min(sumc,(sa[j]-sb[j]*i)/sc[j]);
        if(i+sumc>maxb+maxc) maxb=i,maxc=sumc;
    }
    For(i,1,maxb) printf("%s",b+1);
    For(i,1,maxc) printf("%s",c+1);
    For(i,0,25) if(sa[i]-sb[i]*maxb-sc[i]*maxc>0) putchar(i+97),sa[i]--,i--;
}