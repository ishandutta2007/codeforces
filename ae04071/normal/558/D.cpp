#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;

set<pii> tr;
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	tr.insert(pii(1ll<<(n-1ll),(1ll<<n)-1ll));
	for(int i=0;i<m;i++) {
		int h,ans;
		lli l,r;
		scanf("%d%lld%lld%d",&h,&l,&r,&ans);
		l=max(l,1ll<<(h-1)); r=min(r,(1ll<<h)-1ll);
		if(l>r) continue;

		for(int i=0;i<n-h;i++) l<<=1,r=r<<1|1;
		
		if(ans) {
			auto t=tr.upper_bound(pii(l,1ll<<n));
			if(t!=tr.begin()) {
				t--;
				if(t->first<=l && t->second>=r) {
					tr.clear();
					tr.insert(pii(l,r));
					continue;
				}
			}
			
			for(auto it=tr.begin();it!=tr.end();) {
				if(it->second<l) it=tr.erase(it);
				else {
					lli lv=max(l,it->first),rv=it->second;
					tr.erase(it);
					tr.insert(pii(lv,rv));
					break;
				}
			}
			auto it=tr.upper_bound(pii(r,1ll<<n));
			if(it!=tr.begin()) {
				it--;
				lli lv=it->first, rv=min(r,it->second);
				it=tr.erase(it);
				tr.insert(pii(lv,rv));
			}
			for(;it!=tr.end();) {
				it=tr.erase(it);
			}
		} else {
			auto it=tr.upper_bound(pii(l,1ll<<n));
			if(it!=tr.begin()) {
				it--;
				if(it->first<=l && it->second>=r) {
					lli lv=it->first, rv=it->second;
					tr.erase(it);
					if(lv<=l-1) tr.insert(pii(lv,l-1));
					if(r+1<=rv) tr.insert(pii(r+1,rv));
					continue;
				}
				if(it->second>=l) {
					lli lv=it->first, rv=l-1;
					it=tr.erase(it);
					if(lv<=rv) tr.insert(pii(lv,rv));
				} else it++;
			}
			for(;it!=tr.end();) {
				if(it->second > r) {
					if(it->first <= r)  {
						lli lv=r+1, rv=it->second;
						tr.erase(it);
						if(lv<=rv) tr.insert(pii(lv,rv));
					}
					break;
				} else it=tr.erase(it);
			}
		}
	}

	if(tr.size()==0) {
		puts("Game cheated!");
		return 0;
	}
	if(tr.size()==1) {
		auto it=tr.begin();
		if(it->first == it->second){
			printf("%lld\n",it->first);
			return 0;
		}
	}
	puts("Data not sufficient!");

	return 0;
}