#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long lli;

int n,k,m,cnt[65],v;
lli arr[200000];

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;i++) {
		scanf("%lld",arr+i);

		lli val=arr[i];
		int c=0;
		while(val) {
			if(val&1) cnt[c]++;
			c++;
			val>>=1;
		}
	}
	v=1;
	for(int i=0;i<k;i++) v*=m;

	lli ans=0;
	for(int i=0;i<n;i++) {
		vector<int> a;
		lli val=arr[i];
		int c=0;
		while(val) {
			if(val&1) a.push_back(c);
			c++;
			val>>=1;
		}
		for(auto &it:a) cnt[it]--;
		val = arr[i]*v;
		
		lli res=0;
		for(int i=0;i<63;i++) if(cnt[i] || (val>>i&1)) {
			res|=1ll<<i;
		}
		ans=max(ans,res);
		for(auto &it:a) cnt[it]++;
	}
	printf("%lld\n",ans);
	
	return 0;
}