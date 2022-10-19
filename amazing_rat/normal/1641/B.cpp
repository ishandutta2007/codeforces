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
const int maxn=510;
const int maxm=(1e6)+10;
int n,N,lsh[maxn],T,a[maxn],cnt[maxn];
int tot,pre[maxm],suf[maxm],val[maxm];
vector<pair<int,int> > A,B;
vector<int> V;
int main() {
	read(T);
	while (T--) {
		N=0;
		read(n); for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
		sort(lsh+1,lsh+N+1); N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=N;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh,cnt[a[i]]++;
		int flag=1; for (int i=1;i<=N;i++) flag&=(cnt[i]%2==0);
		if (!flag) { puts("-1"); continue; }
		A.clear(),B.clear();
		tot=n;
		for (int i=1;i<=n;i++) pre[i]=i-1,suf[i]=i+1,val[i]=a[i];
		suf[n]=0;
		for (int i=1,now=1;i;now++) {
			int j=suf[i],T=now+1; V.clear();
			while (j&&val[j]!=val[i]) V.push_back(val[j]),j=suf[j],T++;
			assert(j);
			//printf("%d %d\n",i,j);
			int a=j,b=suf[j];
			for (int &x : V) {
				val[tot+1]=val[tot+2]=x;
				pre[tot+1]=a,suf[tot+1]=tot+2;
				pre[tot+2]=tot+1,suf[tot+2]=b;
				pre[b]=tot+2,suf[a]=tot+1;
				a=tot+1,b=tot+2;
				tot+=2;
				//printf("add %d %d\n",T,x);
				A.push_back(MP(T,x)); T++;
			}
			B.push_back(MP(now,T));
			if (T!=now+1) i=suf[tot-1]; else i=suf[j];
			//printf("> %d %d %d\n",i,now,T);
			now=T;
		}
		printf("%d\n",(int)A.size());
		for (pair<int,int> a : A) printf("%d %d\n",a.first,lsh[a.second]);
		printf("%d\n",(int)B.size());
		for (pair<int,int> a : B) printf("%d ",a.second-a.first+1); puts("");
		for (int i=1;i<=tot;i++) pre[i]=suf[i]=val[i]=0;
	}
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