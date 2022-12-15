#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n;
pii a[200001];
lli W;

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%lld",&n,&W);
		for(int i=0;i<n;i++) scanf("%d",&a[i].first), a[i].second = i+1;
		sort(a,a+n);

		vector<int> ans;
		lli s=0;
		for(int i=n-1;i>=0;i--) {
			if(s + a[i].first <= W) {
				s += a[i].first;
				ans.push_back(a[i].second);
			}
		}
		if(s < (W+1)/2) {
			puts("-1");
		} else {
			printf("%lu\n",ans.size());
			sort(ans.begin(),ans.end());
			for(auto &v:ans) printf("%d ",v);
			puts("");
		}
	}
	return 0;
}