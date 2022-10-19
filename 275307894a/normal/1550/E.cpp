#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define K 17
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,k,x,y,z,l,r,mid,B[N+5],F[N+5][K+5],dp[1<<K+1],rs,tot;char c[N+5];
I int check(int mid){
	re int i,j;for(i=0;i<k;i++) {
		for(j=1;j<=n;j++)B[j]=(c[j]=='?'||c[j]=='a'+i);for(j=n;j;j--) B[j]&&(B[j]=(B[j+1]?B[j+1]:j));
		for(rs=n+1,j=n;j;j--){
			if(B[j]-j+1>=mid)rs=j+mid-1;F[j][i]=rs; 
		}
	}Me(dp,0x3f);dp[0]=0;
	for(i=0;i<(1<<k);i++){
		if(dp[i]>=n) continue;for(j=0;j<k;j++){
			if(i&(1<<j)) continue;dp[i|(1<<j)]=min(dp[i|(1<<j)],F[dp[i]+1][j]);
		} 
	}
	return dp[(1<<k)-1]<=n;
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&k);scanf("%s",c+1);l=0;r=n/k+1;
	while(l+1<r) mid=l+r>>1,(check(mid)?l:r)=mid;printf("%d\n",l);
}