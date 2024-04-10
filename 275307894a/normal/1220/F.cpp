#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (400000+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,x,y,z,A[N],st[N][20],lg[N],l,r,mid,Mx;
I int Qry(int x,int y){int d=lg[y-x+1];return A[st[x][d]]<A[st[y-(1<<d)+1][d]]?st[x][d]:st[y-(1<<d)+1][d];}
I int calc(int l,int r){if(l>r) return 0;int m=l+r>>1,p=Qry(l,r),F1=calc(l,p-1),F2=calc(p+1,r);return max(F1,F2)+1;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);m=2*n;for(i=1;i<=n;i++)scanf("%d",&A[i]),A[i+n]=A[i];for(Mx=1,i=2;i<=n;i++) A[Mx]>A[i]&&(Mx=i);for(i=2;i<=m;i++) lg[i]=lg[i/2]+1;
	for(i=m;i;i--) for(st[i][0]=i,j=1;i+(1<<j)-1<=m;j++) st[i][j]=(A[st[i][j-1]]<A[st[i+(1<<j-1)][j-1]]?st[i][j-1]:st[i+(1<<j-1)][j-1]);
	l=1;r=n+1;while(l+1<r) mid=l+r>>1,(calc(Mx+n-mid+1,Mx+n-1)<=calc(Mx+1,Mx+n-mid)?l:r)=mid;printf("%d %d\n",l>Mx?calc(Mx+n-l+1,Mx+2*n-l):calc(Mx-l+1,Mx-l+n),(Mx-l+n)%n);
}