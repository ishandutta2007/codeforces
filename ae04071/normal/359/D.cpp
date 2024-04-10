#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

int n,arr[300001];
int ll[300001],rr[300001];

int gcd(int a,int b) {
	return b==0 ? a : gcd(b,a%b);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<n;i++) ll[i]=rr[i]=i;
	
	int i=0,g=arr[0];
	for(int j=0;j<n;j++) {
		if(arr[j]%arr[i]!=0) {
			rr[i]=j-1;
			i=j;
		}
	}
	rr[i]=n-1;

	i=n-1;
	g=arr[n-1];
	for(int j=n-1;j>=0;j--) {
		if(arr[j]%arr[i]!=0) {
			ll[i]=j+1;
			i=j;
		} else if(arr[j]==arr[i]) i=j;
	}
	ll[i]=0;

	int mx=0,cnt=0;
	for(int i=0;i<n;i++) {
		int val=rr[i]-ll[i];
		if(val > mx) mx = val;
	}
	set<int> tr;
	for(int i=0;i<n;i++) {
		int val=rr[i]-ll[i];
		if(val == mx) tr.insert(ll[i]+1);
	}
	printf("%d %d\n",SZ(tr),mx);
	for(auto &it:tr) printf("%d ",it);
	
	return 0;
}