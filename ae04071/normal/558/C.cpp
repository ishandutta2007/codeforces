#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int n;
pii arr[100001];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int val;
		scanf("%d",&val);
		for(int j=0;val;j++,val/=2) {
			arr[val].first++;
			arr[val].second+=j;
		}
	}

	int ans=1e9;
	for(int i=100000;i;i--) {
		int cnt=arr[i].first, sum=arr[i].second, val=i;
		if(!(val&1)) {
			val/=2;
			for(int j=1;val;j++,val/=2) {
				sum += (arr[val].second - arr[val<<1].second - cnt) + (arr[val].first - cnt)*j;
				cnt = arr[val].first;
				if(val&1) break;
			}
		}
		if(cnt==n) ans = min(ans,sum);
	}
	printf("%d\n",ans);

	return 0;
}