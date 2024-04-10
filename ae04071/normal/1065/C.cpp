#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

inline int _abs(int a) {return a<0 ? -a : a;}
inline lli _abs(lli a) {return a<0 ? -a : a;}

int n,k,a[200000];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	sort(a,a+n);

	int s=0,ans=0;
	for(int i=n-1,j;i>=0;) {
		for(j=i;j>=0 && a[j]==a[i];j--);

		if(j<0) {
			if(s) ans++;
			break;
		}

		if(s+1ll*(a[i]-a[j])*(n-j-1) < k) {
			s += 1ll*(a[i]-a[j])*(n-j-1);
		} else {
			int t=(k-s)/(n-j-1);
			int ta=k/(n-j-1);
			ans += (a[i]-a[j]-t)/ta + 1;
			s = (a[i]-a[j]-t)%ta*(n-j-1);
		}
		i=j;
	}
	printf("%d\n",ans);

	return 0;
}