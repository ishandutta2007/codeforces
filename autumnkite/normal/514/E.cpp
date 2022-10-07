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
#define MOD 1000000007
struct Mx{
    int n,m,d[102][102];
}a,b;
int n,x;
Mx operator *(Mx a,Mx b){
    Mx c;memset(c.d,0,sizeof c.d);c.n=a.n,c.m=b.m;
    For(i,1,a.n) For(j,1,b.m) For(k,1,a.m){
        (c.d[i][j]+=1ll*a.d[i][k]*b.d[k][j]%MOD)%=MOD;
    }
    return c;
}
inline Mx Pow(Mx a,int b){
    Mx ans=a;
    for(b--;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
    return ans;
}
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    n=read(),x=read();
    if(!x) return printf("1"),0;
    For(i,1,n){
        int d=read();
        b.d[100-d+1][100]++,b.d[100-d+1][101]++;
    }
    For(i,2,100) b.d[i][i-1]=1;
    b.d[101][101]=1,b.n=b.m=101;
    a.d[a.n=1][a.m=101]=a.d[1][100]=1;
    a=a*Pow(b,x);
    write(a.d[1][101]);
    return 0;
}