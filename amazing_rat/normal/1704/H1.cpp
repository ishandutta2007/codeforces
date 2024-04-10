// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=5010;

int n,mod,ans;

int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn];
void init() {
	jc[0]=jc[1]=ivjc[0]=ivjc[1]=1;
	for(int i=2;i<maxn;++i) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=1;i--) ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
}
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int S(int n,int j) {
	return C(n-j-1,j-1);
}
int main() {
	read(n),read(mod);
	init();
	int t=1;
	for (int j=1;j<=n/2;j++) {
		t=(ll)t*(n-1)%mod;
		for (int i=0;i+j*2<=n;i++) {
			int tmp=(ll)ksm(n-j-i,i)*t%mod;
			tmp=(ll)tmp*S(n-i,j)%mod*ivjc[j]%mod*C(n,i)%mod*jc[n-i]%mod;
			update(ans,tmp);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}