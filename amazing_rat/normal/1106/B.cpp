#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,m,a[maxn],c[maxn];
int b[maxn],pos=1;
ll ans;
bool cmp(int x,int y) {
	return a[x]<a[y];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) b[i]=i;
	sort(b+1,b+n+1,cmp);
	int x,y;
	while (m--) {
		read(x); read(y);
		if (c[x]>=y) {
			c[x]-=y;
			printf("%lld\n",(ll)y*a[x]);
			continue;
		}
		ans=(ll)c[x]*a[x]; y-=c[x]; c[x]=0;
		while (pos<=n&&y) {
			int i=b[pos];
			if (c[i]>=y) {
				c[i]-=y;
				ans+=(ll)y*a[i];
				y=0;
				break;
			}
			ans+=(ll)c[i]*a[i];
			y-=c[i]; c[i]=0;
			pos++;
		}
		if (y) ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}