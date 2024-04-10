#include<cstdio>
#include<cmath>
#define mod 1000000007
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,head,lastans,cnt;
int last[200039],root[100039],h[90][100039],a[100039],lg[100039],now;
char st[90][100039][20];
int pr[200039],ph,flag[200039],g[200039];
long long po[90][100039],ans;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
struct tree{int l,r;long long f;}f[6000039];
inline void xj(int &now){f[++cnt]=f[now];now=cnt;}
inline void get(int x,int y,int l,int r,int &now){
	xj(now);
	if(l==r){f[now].f=y;return;}
	int m=l+r>>1;
	if(x<=m)get(x,y,l,m,f[now].l);
	else get(x,y,m+1,r,f[now].r);
	f[now].f=f[f[now].l].f*f[f[now].r].f%mod;
}
inline long long find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].f;
	int m=l+r>>1;
	long long fs=1;
	if(x<=m&&f[now].l) fs=fs*find(x,y,l,m,f[now].l)%mod;
	if(y>m&&f[now].r) fs=fs*find(x,y,m+1,r,f[now].r)%mod;
	return fs;
} 
inline void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	register int i,j,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	f[0].f=1;
	k=sqrt(2e5);pr[0]=1;
	for(i=2;i<=2e5;i++){
		if(!flag[i]) pr[++ph]=i,g[i]=ph;
		for(j=1;j<=ph&&pr[j]*i<=2e5;j++){
			flag[pr[j]*i]=1;g[pr[j]*i]=j;
			if(i%pr[j]==0) break;
		}
	}
	for(i=1;i<=ph;i++) if(pr[i]>k) {head=i-1;break;}
	for(i=1;i<=head;i++){
		po[i][0]=1;
		for(j=1;j<=n;j++) po[i][j]=po[i][j-1]*pr[i]%mod;
	} 
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<=n;i++){
		x=a[i];
		while(x!=pr[g[x]]) h[g[x]][i]++,x/=pr[g[x]];
		if(x>k)a[i]=x;
		else h[g[x]][i]++,a[i]=1;
	} 
	for(i=1;i<=head;i++){
	    for(j=n;j>=1;j--){
	    	st[i][j][0]=h[i][j];
			for(s=1;j+(1<<s)-1<=n;s++)st[i][j][s]=max(st[i][j][s-1],st[i][j+(1<<s-1)][s-1]);
		} 
	}
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		if(last[a[i]]) get(last[a[i]],1,1,n,root[i]);
		last[a[i]]=i;get(i,a[i],1,n,root[i]);
	}
	scanf("%d",&m);
	for	(i=1;i<=m;i++){
		read(x);read(y);
		x=(x+lastans)%n+1;y=(y+lastans)%n+1;
		if(x>y) swap(x,y);
		//printf("%d %d\n",x,y);
		ans=find(x,y,1,n,root[y]);
		now=lg[y-x+1]-1;
		for(j=1;j<=head;j++)ans=ans*po[j][max(st[j][x][now],st[j][y-(1<<now)+1][now])]%mod;
		lastans=ans;
		printf("%lld\n",ans);
	}
}