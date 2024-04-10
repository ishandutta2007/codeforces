#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,m,k,a[maxn];
ll d[maxn],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++)
		d[i]=a[i+1]-a[i]-1;
	sort(d+1,d+n); reverse(d+1,d+n);
	for (int i=1;i<k;i++)
		ans+=d[i];
	ans=a[n]-a[1]+1-ans;
	printf("%lld\n",ans);
	return 0;
}