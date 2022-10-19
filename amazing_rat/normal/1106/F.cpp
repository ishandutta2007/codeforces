#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
int k,n,m,A,B,g=3;
map<int,int> M;
struct Matrix {
	ll d[110][110]; int n,m;
	void init() {
		n=m=k;
		memset(d,0,sizeof(d));
		for (int i=1;i<=n;i++) d[i][i]=1;
	}
} a,b,ans;
Matrix cheng(Matrix x,Matrix y) {
	Matrix z; z.n=x.n; z.m=y.m;
	for (int i=1;i<=z.n;i++)
	for (int j=1;j<=z.m;j++) {
		z.d[i][j]=0;
		for (int K=1;K<=x.m;K++)
			z.d[i][j]+=x.d[i][K]*y.d[K][j]%(mod-1);
		z.d[i][j]%=(mod-1);
	}
	return z;
}
ll ksm(ll x,ll y,ll p) {
	if (y==0) return 1;
	if (y==1) return x%p;
	ll res=ksm(x,y/2,p);
	res=res*res%p;
	if (y&1) res=res*x%p;
	return res;
}
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
void exgcd(int a,int b,int &x,int &y) {
	if (b==0) x=1,y=0;
	else {
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int inverse(int a,int m) {
	int x,y;
	exgcd(a,m,x,y);
	return (x%m+m)%m;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(k);
	for (int i=1;i<=k;i++) read(b.d[k-i+1][k]);
	read(n); read(B);
	for (int i=1;i<k;i++) b.d[i+1][i]=1;
	b.n=b.m=k;
	ans.init(); n-=k;
	while (n) {
		if (n&1) ans=cheng(ans,b);
		n/=2; b=cheng(b,b);
	}
	a.d[1][k]=1; a.n=1; a.m=k;
	ans=cheng(a,ans);
	A=ans.d[1][k];
	m=ceil(sqrt(mod));
	ll tmp=B%mod;
	for (int i=1;i<=m;i++) {
		tmp=tmp*g%mod;
		M[tmp]=i;
	}
	ll iv=ksm(g,m,mod); tmp=1;
	int indb,d=gcd(A,mod-1);
	for (int i=1;i<=m;i++) {
		tmp=tmp*iv%mod;
		if (M[tmp]) {
			indb=i*m-M[tmp]; break;
		}
	}
	if (indb%d!=0) { printf("-1\n"); return 0; }
	indb/=d;
	indb=(ll)indb*inverse(A/d,(mod-1)/d)%((mod-1)/d);
	printf("%lld\n",ksm(g,indb,mod));
	return 0;
}