#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
const int inf=1e9+10;

int n;
lli m,a[200001];
int tr[200001];

void upd(int cur,int val) {
	while(cur<=n) {
		tr[cur] += val; cur += cur & -cur;
	}
}
int get_sum(int cur) {
	int res=0;
	while(cur) {
		res += tr[cur];
		cur-= cur & -cur;
	}
	return res;
}
int main() {
	scanf("%d%lld",&n,&m);
	vector<lli> p;
	lli sum=0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum += a[i];
		p.push_back(sum);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	
	sum=0;
	for(int i=1;i<=n;i++) {
		sum += a[i];
		upd(lower_bound(p.begin(),p.end(),sum)-p.begin()+1,1);
	}
	m--;
	
	lli ans=0;
	sum=0;
	for(int i=1;i<=n;i++) {
		ans += get_sum(upper_bound(p.begin(),p.end(),m)-p.begin());
		sum += a[i];
		m += a[i];
		upd(lower_bound(p.begin(),p.end(),sum)-p.begin()+1,-1);
	}
	printf("%lld\n",ans);

	return 0;
}