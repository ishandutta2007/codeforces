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
const int mod=998244353;
const int maxn=(2e5)+10;
int n,m,mx=200001;
int cnt[maxn],s[maxn],t[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int jc[maxn],ivjc[maxn],ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
namespace BIT {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x<=mx;x+=x&(-x)) tr[x]+=delta;
	}
	int query(int x) {
		int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
	}
};
int main() {
	jc[0]=ivjc[0]=1;
	for (int i=1;i<maxn;i++) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for (int i=maxn-2;i>=1;i--) ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
	read(n),read(m);
	for (int i=1;i<=n;i++) read(s[i]),cnt[s[i]]++;
	for (int i=1;i<=m;i++) read(t[i]);
	int now=1;
	for (int i=1;i<=mx;i++) now=(ll)now*ivjc[cnt[i]]%mod,BIT::add(i,cnt[i]);
	for (int i=1;i<=min(n,m);i++) {
		if (i>1) {
			if (cnt[t[i-1]]==0) break;
			now=(ll)now*cnt[t[i-1]]%mod;
			cnt[t[i-1]]--;
			BIT::add(t[i-1],-1);
		}
		int tmp=(ll)now*jc[n-i]%mod;
		tmp=(ll)tmp*BIT::query(t[i]-1)%mod;
		update(ans,tmp);
	}
	if (n<m) {
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[s[i]]++,cnt[t[i]]--;
		int flag=1;
		for (int i=1;i<=mx&&flag;i++) flag&=(cnt[i]==0);
		update(ans,flag);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/