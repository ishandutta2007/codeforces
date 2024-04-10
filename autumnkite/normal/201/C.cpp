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
int n;
LL a[N],l[N],r[N],s[N],ans;
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    s[1]=l[1]=r[n=read()]=0;
    For(i,1,n-1) a[i]=read(),s[i+1]=s[i]+(a[i]&1?a[i]:a[i]-1);
    For(i,2,n) l[i]=a[i-1]>1?(l[i-1]+a[i-1]-(a[i-1]&1)):0;
    DFor(i,n-1,1) r[i]=a[i]>1?(r[i+1]+a[i]-(a[i]&1)):0;
    ans=l[1]+r[1];int m=1;
    For(i,2,n){
        if(l[i]-s[i]>l[m]-s[m]) m=i;
        ans=Max(ans,l[m]-s[m]+r[i]+s[i]);
    }
    write(ans);
    return 0;
}