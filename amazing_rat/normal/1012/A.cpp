#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int n;
ll a[maxn],ans=(2e18);
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=2*n;i++) read(a[i]);
	sort(a+1,a+2*n+1);
	for (int i=2;i<=n;i++)
		ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	ans=min(ans,(a[n]-a[1])*(a[2*n]-a[n+1]));
	printf("%lld\n",ans);
	return 0;
}