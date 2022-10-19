#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,Q,mx,tot;
int d[maxn],ans;
int a[maxn],b[maxn];
ll m;
deque<int> q;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	read(Q);
	int x,y;
	for (int i=1;i<=n;i++) {
		read(d[i]),mx=max(mx,d[i]);
		q.push_back(d[i]);
	}
	while (!q.empty()) {
		if (q.front()==mx) break;
		a[++tot]=q.front(); q.pop_front();
		b[tot]=q.front(); q.pop_front();
		x=a[tot]; y=b[tot];
		if (x<y) swap(x,y);
		q.push_front(x);
		q.push_back(y);
	}
	for (int i=1;i<=n;i++)
		d[i]=q.front(),q.pop_front();
	while (Q--) {
		read(m);
		if (m<=tot) printf("%d %d\n",a[m],b[m]);
		else {
			m-=tot;
			if (m%(n-1)==0) ans=d[n];
			else ans=d[m%(n-1)+1];
			printf("%d %d\n",mx,ans);
		}
	}
	return 0;
}