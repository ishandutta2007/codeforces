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
#define N 400005
int n,q,st0[N][25];
LL w[N],st1[N][25],last;
int main(){
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    n=1,q=read();
    while(q--){
        int k=read();LL r=read()^last,W=read()^last;
        if(k==1){
            w[++n]=W;
            if(w[r]>=W) st0[n][0]=r;
            else{
                DFor(i,20,0) if(st0[r][i]&&w[st0[r][i]]<W) r=st0[r][i];
                st0[n][0]=st0[r][0];
            }
            st1[n][0]=w[st0[n][0]];
            For(i,1,20){
                st0[n][i]=st0[st0[n][i-1]][i-1];
                st1[n][i]=st1[n][i-1]+st1[st0[n][i-1]][i-1];
            }
        }
        else{
            LL sum=w[r];last=1;
            if(sum>W){last=0;printf("0\n");continue;}
            DFor(i,20,0) if(sum+st1[r][i]<=W&&st0[r][i]) sum+=st1[r][i],r=st0[r][i],last+=(1<<i);
            write(last),putchar('\n');
        }
    }
    return 0;
}