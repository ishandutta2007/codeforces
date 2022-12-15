#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional> 
#include <stack>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n;
lli arr[200001];
int main() {
	int cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n*2;i++) scanf("%lld",arr+i);
	sort(arr,arr+n*2);
	
	lli mx=(arr[n-1]-arr[0])*(arr[2*n-1]-arr[n]);
	for(int i=1;i<n;i++) {
		mx=min(mx,(arr[i+n-1]-arr[i])*(arr[2*n-1]-arr[0]));
	}
	printf("%lld\n",mx);
	
	return 0;
}