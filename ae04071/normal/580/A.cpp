#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX=1<<17;
struct seg_tr{
	int tr[MAX<<1];
	void upd(int cur,int val) {
		cur+=MAX;
		tr[cur]=max(tr[cur],val);
		cur>>=1;
		while(cur) {
			tr[cur]=max(tr[cur<<1],tr[cur<<1|1]);
			cur>>=1;
		}
	}
	int find(int l,int r) {
		int res=0;
		l+=MAX; r+=MAX;
		while(l<=r) {
			res=max({res,tr[l],tr[r]});
			if(l&1) l++;
			if(!(r&1)) r--;
			l>>=1; r>>=1;
		}
		return res;
	}
}tr;

int n,a[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	int ans=0;
	for(int i=0;i<n;) {
		int j=i+1;
		for(;j<n && a[j-1]<=a[j];j++);
		ans=max(ans,j-i);
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}