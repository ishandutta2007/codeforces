#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(4e5)+10;
int n,x,y,a,b,tot;
map<int,int> cnt;
map<int,int>::iterator it;
vector<int> g[maxn];
int s[maxn];
vector<int> ans[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(x),cnt[x]++;
	for (it=cnt.begin();it!=cnt.end();it++)
		g[it->second].push_back(it->first);
	for (int i=n;i>=1;i--) s[i]=s[i+1]+g[i].size();
	for (int i=1,j;i<=n;i++) {
		tot+=s[i];
		j=tot/i;
		if (j>=i&&a*b<i*j) a=i,b=j;
	}
	for (int i=0;i<a;i++) ans[i].resize(b);
	x=0,y=0;
	for (int i=n;i>=1;i--)
	for (int j=0;j<g[i].size();j++) {
		tot=min(i,a);
		while (tot--) {
			if (ans[x][y]) x=(x+1)%a;
			if (!ans[x][y]) ans[x][y]=g[i][j];
			x=(x+1)%a,y=(y+1)%b;
		}
	}
	printf("%d\n%d %d\n",a*b,a,b);
	for (int i=0;i<a;i++) {
		for (int j=0;j<b;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/