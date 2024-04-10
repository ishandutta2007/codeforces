#include <cstdio>
#include <set>
#include <utility>

const int INF=1e9+7;
typedef std::pair<int, int> ip;
std::set<ip> f[4],t[4];
int n,p[200000],a[200000],b[200000],m;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",p+i);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",b+i);
	for(int i=0;i<n;i++) {
		f[a[i]].insert(ip(p[i],b[i]));
		t[b[i]].insert(ip(p[i],a[i]));
	}
	scanf("%d",&m);
	while(m--) {
		int val;
		scanf("%d", &val);
		int max=INF, idx=-1;
		if(f[val].size()>0&&f[val].begin()->first<max) {
			max=f[val].begin()->first; idx=0;
		}
		if(t[val].size()>0&&t[val].begin()->first<max) {
			max=t[val].begin()->first; idx=1;
		}
		if(max!=INF) printf("%d ",max);
		else printf("-1 ");
		if(idx==0) {
			int bt=f[val].begin()->second;
			f[val].erase(ip(max,bt));
			t[bt].erase(ip(max,val));
		}
		else {
			int ft=t[val].begin()->second;
			t[val].erase(ip(max,ft));
			f[ft].erase(ip(max,val));
		}
	}
			
	return 0;
}