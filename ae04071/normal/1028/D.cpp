#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

const int mod=1e9+7;

set<int> gt,r;
set<int, greater<int>> lt;
int n;
char str[30];

int main() {
	scanf("%d",&n);
	int ans=1,val;
	while(n--) {
		scanf("%s %d",str,&val);
		if(str[2]=='C') {
			if(r.find(val)!=r.end()) {
				r.erase(val);
				ans=ans*2%mod;
				for(auto &it:r) {
					if(it<val) lt.insert(it);
					else gt.insert(it);
				}
				r.clear();
			} else if(!lt.empty() && *lt.begin()==val) {
				lt.erase(lt.begin());
				for(auto &it:r) gt.insert(it);
				r.clear();
			}
			else if(!gt.empty() && *gt.begin()==val) {
				gt.erase(gt.begin());
				for(auto &it:r) lt.insert(it);
				r.clear();
			}
			else {
				puts("0");
				return 0;
			}
		} else {
			if(!lt.empty() && *lt.begin()>val) lt.insert(val);
			else if(!gt.empty() && *gt.begin()<val) gt.insert(val);
			else r.insert(val);
		}
	}
	ans=(1ll*ans*(int)(r.size()+1))%mod;
	printf("%d\n",ans);
	
	return 0;
}