#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,ans[maxn],a[maxn];
pair<int,int> b[maxn];
int s,f[maxn],lst;
bool cmp(pair<int,int> x,pair<int,int> y) {
	return abs(x.first)>abs(y.first);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<=n;i++) {
		read(x);
		b[i].second=i;
		if (abs(x)>=abs(-x-1)) {
			if (x<0) f[i]=1;
			b[i].first=x;
		} else {
			if (-x-1<0) f[i]=1;
			b[i].first=-x-1;
		}
		a[i]=x;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) {
		x=b[i].second;
		s+=f[x];
		ans[x]=b[i].first;
		//printf("%d %d\n",x,b[i].first);
	}
	if (s%2==1) {
		for (int i=1;i<=n;i++)
			if (!lst||ans[i]<ans[lst]) lst=i;
		ans[lst]=-ans[lst]-1;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}