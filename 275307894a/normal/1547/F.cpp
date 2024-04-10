#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 400000
#define M 20000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int T,n,m,A[N+5],B[N+5],l,r,mid,now,st[N+5][20],lg[N+5];
I int find(int x,int y){now=lg[y-x+1];return __gcd(st[x][now],st[y-(1<<now)+1][now]);}
I int check(int mid){
	re int i;for(i=1;i<=n;i++) {B[i]=find(i,i+mid);if(i^1&&B[i]^B[i-1]) return 0;}return 1;
} 
I void Solve(){
	re int i,j;scanf("%d",&n);m=2*n;for(i=1;i<=n;i++)scanf("%d",&A[i]),A[n+i]=A[i];
	for(i=m;i;i--)  for(st[i][0]=A[i],j=1;i+(1<<j)-1<=m;j++)st[i][j]=__gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
	l=-1;r=n;while(l+1<r) mid=l+r>>1,(check(mid)?r:l)=mid;printf("%d\n",r);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;for(i=2;i<=N;i++) lg[i]=lg[i/2]+1;scanf("%d",&T);while(T--) Solve();
}