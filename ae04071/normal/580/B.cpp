#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

int n,m;
pii a[100000];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);

	long long sum=0,ans=0;
	sort(a,a+n);
	
	int i=0,j=0;
	for(;j<n;j++) {
		while(i<n && a[i].first+m<=a[j].first) {
			sum-=a[i++].second;
		}
		sum+=a[j].second;
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);

	return 0;
}