#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int n;
pii arr[100000];
int cnt[201];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].first);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].second);
	sort(arr,arr+n);
	

	int ans=1e9,pr=0;
	for(int i=0;i<n;i++) pr+=arr[i].second;
	for(int i=0;i<n;) {
		int j=i;
		for(;j<n && arr[i].first==arr[j].first;j++)
			pr-=arr[j].second;
		
		int nd=max(j - ((j-i)*2-1),0),sum=0;
		for(int k=1;k<=200;k++) {
			if(nd < cnt[k]) {
				sum+=nd*k;
				break;
			} else {
				sum+=cnt[k]*k;
				nd-=cnt[k];
			}
		}
		ans = min(ans,sum+pr);
		for(int k=i;k<j;k++) cnt[arr[k].second]++;
		i=j;
	}
	printf("%d\n",ans);

	return 0;
}