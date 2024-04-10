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
int n,a[N],Log2[N];LL dp[N],ans;
struct node{
    int id,val;
}f[N][25];
inline node Max(node a,node b){return a.val>=b.val?a:b;}
inline int query(int l,int r){
    int k=Log2[r-l+1];
    return Max(f[l][k],f[r-(1<<k)+1][k]).id;
}
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    n=read(),f[n][0]=(node){n,n};
    Log2[1]=0;For(i,2,n) Log2[i]=Log2[i>>1]+1;
    For(i,1,n-1) f[i][0]=(node){i,a[i]=read()};
    For(j,1,20){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=Max(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
    }
    DFor(i,n-1,1){
        int k=query(i+1,a[i]);
        ans+=dp[i]=dp[k]-(a[i]-k)+n-i;
    }
    write(ans);
    return 0;
}