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
#define m 667
#define N 305
#define rep(r) for(i=1,j=0;j+len[i]<(int)(r);i=b[i]) j+=len[i]
int n,w,ans,c[N][100005],b[N],len[N],a[N][1500];
inline int count(int p,int v){
    int i,j,s=0;
    rep(p),s+=c[i][v];j=p-j;
    For(k,1,j) if(a[i][k]==v) s++;
    return s;
}
int main(){
    n=read(),w=(n-1)/m+1,ans=0;
    for(int i=0,t;i<n;i++) t=i/m+1,c[t][a[t][++len[t]]=read()]++;
    For(i,1,w-1) b[i]=i+1;
    for(int q=read();q--;){
        int opt=read(),l=(read()+ans-1)%n+1,r=(read()+ans-1)%n+1;
        if(l>r) swap(l,r);
        if(opt==1){
            if(l==r) continue;
            int i,j,t;
            rep(r);j=r-j,c[i][t=a[i][j]]--,len[i]--;
            For(k,j,len[i]) a[i][k]=a[i][k+1];
            rep(l);j=l-j,c[i][t]++,len[i]++;
            DFor(k,len[i],j+1) a[i][k]=a[i][k-1];
            a[i][j]=t;
            if(len[i]==(m<<1)){
                w++;
                For(k,m+1,len[i]) c[i][a[i][k]]--,c[w][a[w][++len[w]]=a[i][k]]++;
                len[i]=m,b[w]=b[i],b[i]=w;
            }
        }
        else{
            int z=(read()+ans-1)%n+1;
            write(ans=count(r,z)-count(l-1,z)),putchar('\n');
        }
    }
    return 0;
}