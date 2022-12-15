#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

#define sz(x) ((int)x.size())
#define fi first
#define se second

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

set<pll> tr;
int n,m;
pll arr[200001];
int ans[200001];

struct data{
	lli l,r;
	int i;
	bool operator<(const data &rhs)const {
		return r<rhs.r;
	}
}a[200001];

int main() {
	lli val;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld%lld",&arr[i].fi,&arr[i].se);
	for(int i=0;i<m;i++) scanf("%lld",&val),tr.insert(pll(val,i));
	
	for(int i=0;i<n-1;i++) {
		assert(arr[i+1].fi > arr[i].se);
		a[i].l=arr[i+1].fi-arr[i].se;
		a[i].r=arr[i+1].se-arr[i].fi;
		a[i].i=i;
	}
	n--;
	
	sort(a,a+n);

	for(int i=0;i<n;i++) {
		auto it=tr.lower_bound(pll(a[i].l,0));
		if(it==tr.end() || it->first > a[i].r) {
			puts("No");
			return 0;
		}
		ans[a[i].i]=it->second;
		tr.erase(it);
	}

	puts("Yes");
	for(int i=0;i<n;i++) printf("%d ",ans[i]+1);

	return 0;
}