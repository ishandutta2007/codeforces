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
const int maxn=(1e5)+10;
int n,m;
vector<pair<int,int> > V[maxn];
vector<int> X,Y;
ll ans;
int rem[maxn];
void solve(vector<int> &X) {
	sort(X.begin(),X.end());
	for (int i=0;i<X.size();i++) {
		int cnt=i-((int)X.size()-i-1);
		ans+=(ll)cnt*X[i];
	}
	//for (int &x : X) printf("%d ",x); puts("");
}
int main() {
	read(n),read(m); int mx=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		int x; read(x); V[x].push_back(MP(i,j));
		mx=max(mx,x);
	}
	for (int i=1;i<=mx;i++) {
		vector<int> X,Y;
		for (pair<int,int> &A : V[i]) X.push_back(A.first),Y.push_back(A.second);
		solve(X),solve(Y);
	}
	printf("%lld\n",ans);
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