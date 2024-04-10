#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,q[150039],head,tail,now,last;
long long a[1039],b[1039],c[1039],f[2][150039],nows,ans=-1e18;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	for(i=1;i<=m;i++){
		nows=(c[i]-c[i-1])*k;
		nows=min(nows,n);
		now=i&1;last=now^1;
		head=tail=0;
		for(j=1;j<=n;j++){
			while(head!=tail&&j-q[head+1]>nows) head++;
			while(head!=tail&&f[last][q[tail]]<f[last][j]) tail--;
			q[++tail]=j;
			f[now][j]=f[last][q[head+1]];
		}
		head=tail=0;
		for(j=n;j;j--){
			while(head!=tail&&q[head+1]-j>nows) head++;
			while(head!=tail&&f[last][q[tail]]<f[last][j]) tail--;
			q[++tail]=j;
			f[now][j]=max(f[last][q[head+1]],f[now][j]);
		}
		for(j=1;j<=n;j++) f[now][j]+=b[i]-abs(a[i]-j);
	}
	for(i=1;i<=n;i++) ans=max(ans,f[m&1][i]);
	printf("%I64d\n",ans);
}