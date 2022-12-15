#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;

typedef pair<int,int> pii;

int n,a[2001],b[2001],tar[2001];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);

	for(int i=1;i<=n;i++) tar[b[i]]=i;
	for(int i=1;i<=n;i++) a[i] = tar[a[i]];

	int ans=0;
	vector<pii> res;
	for(int i=n;i;i--) {
		int j=1;
		for(;j<=i && a[j]!=i; j++);
		for(int k=j+1;k<=i;k++) if(a[k] <= j) {
			ans += k-j;
			res.push_back(pii(j,k));
			swap(a[j], a[k]);
			j=k;
		}
	}
	
	printf("%d\n",ans);
	printf("%d\n",sz(res));
	for(auto &v:res) printf("%d %d\n",v.fi,v.se);
	
	return 0;
}