#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>
#include <assert.h>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define double long double
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

const lli inf=2e18;
lli add(lli a,lli b) {
	return min(a+b,inf);
}
lli fib[51];
int n;
lli k;

int main() {
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=50;i++) fib[i] = add(fib[i-1],fib[i-2]);
	
	scanf("%d%lld",&n,&k);
	vector<int> ans;
	for(int i=1;i<=n;) {
		if(fib[n-i]<k) {
			ans.push_back(i+1); ans.push_back(i);
			k-=fib[n-i];
			i+=2;
		} else {
			ans.push_back(i);
			i++;
		}
	}
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	
	return 0;
}