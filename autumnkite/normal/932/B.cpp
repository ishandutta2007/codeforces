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
#define N 1000005
int n=1000000,f[N],g[N],sum[10][N];
inline int G(int x){
    if(g[x]) return g[x];
    if(x<10) return g[x]=x;else return g[x]=G(f[x]);
}
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    f[0]=1;For(i,1,n) f[i]=f[i/10]*(i%10?i%10:1);
    For(i,1,n) g[i]=G(i);
    For(i,1,n){
        For(j,1,9) sum[j][i]=sum[j][i-1];
        sum[g[i]][i]++;
    }
    for(int q=read();q--;putchar('\n')){
        int l=read(),r=read(),k=read();
        write(sum[k][r]-sum[k][l-1]);
    }
    return 0;
}