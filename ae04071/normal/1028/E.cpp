#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;

int n;
lli arr[200000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);

	vector<pli> ans;
	for(int i=0;i<n;i++) {
		if(arr[i] < arr[(i+1)%n]) {
			ans.push_back(pli(arr[(i+1)%n],(i+1)%n));
			
			int cur=i;
			while(cur!=(i+1)%n) {
				if(cur==(i+1)%n) {
					ans.push_back(pli(ans.back().first+arr[cur],cur));
				} else {
					int pr=(cur+n-1)%n;
					ans.push_back(pli( (arr[pr]/ans.back().first+1)*ans.back().first+arr[cur], cur));
				}
				cur=(cur+n-1)%n;
			}
			break;
		}
	}
	if(ans.empty()) {
		if(arr[0]) {
			puts("NO");
			return 0;
		}
		else {
			for(int i=0;i<n;i++) ans.push_back(pli(1,i));
		}
	}

	sort(ans.begin(), ans.end(), [](const pli &a,const pli &b){
		return a.second < b.second;
	});
	puts("YES");
	for(auto &v:ans) printf("%lld ",v.first);

	return 0;
}