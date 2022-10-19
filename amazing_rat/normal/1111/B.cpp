#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n;
ll k,m,a[maxn],sum;
double ans,s;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k); read(m);
	for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	for (int i=0;i<=n;i++) {
		if (i>m) break;
		sum-=a[i];
		s=sum+min(k*(n-i),m-i);
		s/=(n-i)*1.0;
		if (s-ans>1e-6) ans=s;
	}
	printf("%.10lf\n",ans);
	return 0;
}