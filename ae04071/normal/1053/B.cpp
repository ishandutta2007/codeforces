#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef long long lli;

int n;
lli arr[300001],sum[300001],p[300001][2];

int main() {
	lli ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",arr+i);

		int c=0;
		for(int j=0;j<60;j++) if(arr[i]>>j & 1) {
			c++;
		}
		sum[i] = sum[i-1] + c;
		p[i][0] = p[i-1][0];
		p[i][1] = p[i-1][1];
		p[i][sum[i]%2] += 1;
	}

	for(int i=0;i<n;i++) {
		int v = sum[i]%2;
		ans += p[n][v] - p[i][v]; 
	}
	for(int i=1;i<=n;i++) {
		int r=i,l=i;
		while(r<=n && sum[r]-sum[i-1] < 2*(sum[i]-sum[i-1])) r++;
		r--;
		for(;l>=1;l--) {
			while(r>=i && sum[r]-sum[l-1] >= 2*(sum[i]-sum[i-1])) r--;
			if(r<i) break;
			
			int v=sum[l-1]%2;
			ans -= p[r][v] - p[i-1][v];
		}
	}
	printf("%lld\n",ans);

	return 0;
}