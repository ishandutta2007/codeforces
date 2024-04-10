#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
#define LL long long

const int N=2e5+10;

struct comp {
	bool operator() (const int &a, const int &b) const {return a>b;}
};
int gcd(int a, int b) {return b?gcd(b, a%b):a;}

int p[N], c[N];

int tmp[N], n;
LL k;
bool check(int l) {
	memcpy(tmp, c, sizeof(c)); sort(tmp+1, tmp+1+l, comp());
//	printf("%d:\n", l);
//	for (int i=1; i<=l; i++) printf("%d ", tmp[i]); puts("");
	LL ans=0;
	for (int i=1; i<=l; i++) {
		ans+=tmp[i]*p[i];
		if (ans>=k) break;
	}
	return ans>=k;
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d", p+i), p[i]/=100;
		int x, y, a, b; scanf("%d%d%d%d", &x, &a, &y, &b);
		for (int i=a; i<=n; i+=a) c[i]+=x;
		for (int i=b; i<=n; i+=b) c[i]+=y;
		sort(p+1, p+1+n, comp());
		scanf("%lld", &k);
		int l=0, r=n;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n", l==n+1?-1:l);
	}
	return 0;
}