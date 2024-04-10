#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>

using namespace std;
typedef long long lli;

const int MAX=1<<14;
vector<int> tr[MAX<<1];

int n,q;

void upd(int cur,int s,int f,int l,int r,int val) {
	if(f<l || s>r) return;
	else if(l<=s && f<=r) tr[cur].push_back(val);
	else {
		int nx=cur<<1,md=(s+f)>>1;
		upd(nx,s,md,l,r,val); upd(nx+1,md+1,f,l,r,val);
	}
}
bitset<10001> get(int cur,int s,int f,bitset<10001> pr) {
	for(auto &it:tr[cur]) pr |= pr<<it;
	if(s==f) return pr;

	int nx=cur<<1,md=(s+f)>>1;
	return get(nx,s,md,pr) | get(nx+1,md+1,f,pr);
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=0;i<q;i++) {
		int l,r,v;
		scanf("%d%d%d",&l,&r,&v);
		upd(1,0,MAX-1,l,r,v);
	}
	bitset<10001> ans;
	ans[0]=1;
	ans=get(1,0,MAX-1,ans);
	
	int s=0;
	for(int i=1;i<=n;i++) if(ans[i]==1) s++;
	printf("%d\n",s);
	for(int i=1;i<=n;i++) if(ans[i]==1) printf("%d ",i);
	return 0;
}