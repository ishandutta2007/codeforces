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
int T,n;
multiset<ll> s;
ll all;
map<ll,int> M;
bool DFS(ll x) {
	if (s.find(x)!=s.end()) return 1;
	if (M.count(x)) return 0;
	M[x]=1;
	return DFS(x/2)||DFS((x+1)/2);
}
bool dfs(ll x) {
	if (s.find(x)!=s.end()) { s.erase(s.find(x)); return 1; }
	M.clear();
	if (!DFS(x)) return 0;
	if (dfs(x/2)&&dfs((x+1)/2)) return 1;
	return 0;
}
int main() {
	read(T);
	while (T--) {
		read(n);
		s.clear(); all=0;
		for (int i=1;i<=n;i++) { int x; read(x); s.insert(x); all+=x; }
		if (dfs(all)) puts("Yes"); else puts("No");
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