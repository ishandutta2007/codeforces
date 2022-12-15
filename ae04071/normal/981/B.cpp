#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <set>
#include <cstring>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))

using namespace std;
typedef pair<int,int> pii;
typedef long long lli;

pii arr[100000],brr[100000];
int n,m;

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&arr[i].fi,&arr[i].se);
	scanf("%d",&m);
	for(int j=0;j<m;j++) scanf("%d%d",&brr[j].fi,&brr[j].se);
	sort(arr,arr+n);
	sort(brr,brr+m);

	int i=0,j=0;
	lli sum=0;
	while(i<n || j<m) {
		if(i==n) sum+=brr[j++].se;
		else if(j==m) sum+=arr[i++].se;
		else {
			if(arr[i].fi<brr[j].fi) sum+=arr[i++].se;
			else if(arr[i].fi>brr[j].fi)sum+=brr[j++].se;
			else sum+=max(arr[i++].se,brr[j++].se);
		}
	}
	printf("%lld\n",sum);
	return 0;
}