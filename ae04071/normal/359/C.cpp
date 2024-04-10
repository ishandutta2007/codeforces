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

const lli mod=1e9+7;
lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}

int n,x;
lli arr[100001];
int main() {
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);
	
	lli sum=0;
	for(int i=0;i<n;i++) sum+=arr[i];
	
	priority_queue<lli,vector<lli>, greater<lli> > que;
	for(int i=0;i<n;i++) que.push(sum - arr[i]);

	int c=0;
	lli pr=-1;
	while(!que.empty()) {
		lli cur=que.top();que.pop();
		if(pr==-1) pr=cur, c=1;
		else {
			if(pr!=cur) break;
			
			c++;
			if(c==x) {
				que.push(cur+1);
				pr=-1;
				c=0;
			}
		}
	}
	
	lli res = min(pr, sum);
	printf("%lld\n",power(x,res));

	return 0;
}