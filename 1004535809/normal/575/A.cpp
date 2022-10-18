#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=5e4;
const int SIZE=2;
ll x;int mod,n,m,k,b[MAXN+5];
pair<ll,int> p[MAXN+5];
ll tk[MAXN*2+5];
struct mat{
	int a[SIZE][SIZE];
	mat(){memset(a,0,sizeof(a));}
	friend mat operator *(mat x,mat y){
		mat ret;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			ret.a[i][j]=(ret.a[i][j]+1ll*x.a[i][k]*y.a[k][j]%mod)%mod;
		return ret;
	}
};
struct node{int l,r;mat val;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int p,mat x){
	if(s[k].l==s[k].r){s[k].val=x;return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(p<=mid) modify(k<<1,p,x);else modify(k<<1|1,p,x);
	s[k].val=s[k<<1].val*s[k<<1|1].val;
}
mat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)*query(k<<1|1,mid+1,r);
}
mat qpow(mat x,ll e){
	mat ret;ret.a[0][0]=ret.a[1][1]=1;
	while(e){if(e&1) ret=ret*x;x=x*x;e>>=1;}
	return ret;
}
map<ll,int> mmp;
signed main(){
//	freopen("in.txt","r",stdin);
	scanf("%lld%d%d",&x,&mod,&n);x--;
	if(x==-1) return printf("0\n"),0;
	for(int i=0;i<n;i++) scanf("%d",&b[i]);scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%lld%d",&p[i].fi,&p[i].se);
	for(int i=1;i<=m;i++) mmp[p[i].fi]=p[i].se;
	for(int i=1;i<=m;i++){
		tk[++k]=p[i].fi;
		if(p[i].fi!=n) tk[++k]=p[i].fi-1;
	}
	sort(tk+1,tk+k+1);k=unique(tk+1,tk+k+1)-tk-1;build(1,0,n-1);
	for(int i=0;i<n;i++){
		mat t;t.a[0][0]=0;t.a[1][0]=1;t.a[0][1]=b[i];
		if(!mmp[i+1]) t.a[1][1]=b[(i+1)%n];else t.a[1][1]=mmp[i+1];
		modify(1,i,t);
	}
	mat ret;
	if(x<n) ret=query(1,0,x);
	else{
		ret=query(1,0,n-1);
		if(mmp[n]){
			mat t;t.a[0][0]=0;t.a[1][0]=1;t.a[0][1]=b[n-1];t.a[1][1]=b[0];
			modify(1,n-1,t);
		}
		int cur=1,pre=0;ll pn=0;bool flg=0;
		while(cur<=k){
//			puts("-1");
//			printf("%d %d %d\n",cur,pn,pre);
			if(x/n<tk[pre+1]/n){
				ret=ret*qpow(query(1,0,n-1),(x/n)-pn-1);
				ret=ret*query(1,0,x%n);flg=1;break;
			}
			ret=ret*qpow(query(1,0,n-1),(tk[pre+1]/n)-pn-1);
			while(cur<=k&&tk[cur]/n==tk[pre+1]/n){
				ll id=tk[cur];int v1,v2;
				if(!mmp[id]) v1=b[id%n];else v1=mmp[id];
				if(!mmp[id+1]) v2=b[(id+1)%n];else v2=mmp[id+1];
//				printf("%lld %d %d %d\n",id,id%n,v1,v2);
				mat t;t.a[0][0]=0;t.a[1][0]=1;t.a[0][1]=v1;t.a[1][1]=v2;
				modify(1,id%n,t);cur++;
			}
			if((x/n)==(tk[pre+1]/n)){
				ret=ret*query(1,0,x%n);flg=1;break;
			} else ret=ret*query(1,0,n-1);
			for(int i=pre+1;i<cur;i++){
				mat t;t.a[0][0]=0;t.a[1][0]=1;
				t.a[0][1]=b[tk[i]%n];t.a[1][1]=b[(tk[i]+1)%n];
				modify(1,tk[i]%n,t);
			}
			pn=tk[pre+1]/n;pre=cur-1;
		}
		if(!flg){
//			puts("-1");
			ret=ret*qpow(query(1,0,n-1),(x/n)-pn-1);
			ret=ret*query(1,0,x%n);
		}
	}
	mat f;f.a[0][1]=1;f=f*ret;
	printf("%d\n",f.a[0][0]);
	return 0;
}
/*
3 998244353
3
1 2 1
3
3 3
4 6
10 8

20 998244353
3
100 370 250
5
7 230
23 500
5 480
15 530
19 570

100 998244353
3
1 2 1
2
3 2
5 1

1000000 998244353
3
100 370 250
5
7 230
23 500
5 480
15 530
19 570
*/