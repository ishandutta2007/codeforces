#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#define LL long long
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define DFor(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define cross(i,a) for(int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL read(){
    LL x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(LL x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10),putchar(x%10+'0');
    else putchar(x+'0');
}
#define N 100005
int n,a[N],x[N],y[N],cntx,cnty;
LL k,MAX,l,r,mid,ans,sum;
LL count(LL x){
    LL sum=x*n;
    For(i,1,n) if(a[i]<x) sum-=x-a[i];
    return sum;
}
int main(){
    n=read(),k=read();
    For(i,1,n) MAX=Max(MAX,a[i]=read()),sum+=a[i];
    if(sum<k) return printf("-1\n"),0;
    l=0,r=MAX+1;
    while(l<=r) if(count(mid=l+r>>1)<=k) ans=mid,l=mid+1;else r=mid-1;
    sum=k-count(ans);
    cntx=cnty=0;
    For(i,1,n){
        if(a[i]==ans+1) sum?sum--:x[++cntx]=i;
        else if(a[i]>ans+1) sum?(sum--,y[++cnty]=i):x[++cntx]=i;
    }
    For(i,1,cntx) write(x[i]),putchar(' ');
    For(i,1,cnty) write(y[i]),putchar(' ');
    return 0;
}