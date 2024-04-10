#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,m,q,fa[maxn],ans;
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(q); int x,y;
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=q;i++) {
		read(x); read(y);
		fa[find(x)]=find(y+n);
	}
	for (int i=1;i<=n+m;i++)
		if (find(i)==i) ans++;
	printf("%d\n",ans-1);
	return 0;
}