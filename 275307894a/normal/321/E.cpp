#include<cstdio>
#include<cstring>
#define N 4039
#define K 839
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[N][N],dp[N][K],head,tail,l,r,mid;
I void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
struct ques{int l,r,id;}q[N];
I int calc(int x,int k,int z){return dp[x][k]+a[z][z]-a[z][x]-a[x][z]+a[x][x];}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,h;read(n);read(k);memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) read(a[i][j]),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	for(i=1;i<=k;i++){
		q[head=tail=0]=(ques){1,n,0};
		for(j=1;j<=n;j++){
			while(head<=tail&&q[head].r<j) head++;dp[j][i]=calc(q[head].id,i-1,j);
			while(head<=tail&&(q[tail].l=max(q[tail].l,j))&&calc(q[tail].id,i-1,q[tail].l)>=calc(j,i-1,q[tail].l)) tail--;
			if(head>tail){q[++tail]=(ques){j,n,j};continue;}l=q[tail].l;r=q[tail].r+1;
			while(l+1<r) mid=l+r>>1,(calc(q[tail].id,i-1,mid)<calc(j,i-1,mid)?l:r)=mid;
			q[tail].r=l;r<=n&&(q[++tail]=(ques){r,n,j},0);
		}
	}
	printf("%d\n",dp[n][k]/2);
}