#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,k;
int use[100001],cnt[100001],rem[100001],ord[100001];
vector<int> adj[100001];

struct frac{
	lli a,b;
	int idx;
	frac() {}
	frac(lli a,lli b,int idx):a(a),b(b),idx(idx) {}
	bool operator<(const frac &rhs)const {
		return a*rhs.b < b*rhs.a;
	}
	bool operator>(const frac &rhs)const {
		return a*rhs.b > b*rhs.a;
	}
};

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++) {
		int val;
		scanf("%d",&val);
		use[val]=1;
	}
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a]++; cnt[b]++;
		if(!use[b]) rem[a]++;
		if(!use[a]) rem[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	priority_queue<frac,vector<frac>,greater<frac>> que;
	for(int i=1;i<=n;i++) if(!use[i]) {
		if(cnt[i]==0) cnt[i]=1;
		que.push(frac(rem[i],cnt[i],i));
	}
	
	frac mx(0,1,0);
	int mi=n-k;
	for(int i=1;i<=n-k;i++) {
		while(!que.empty() && que.top().a!=rem[que.top().idx]) que.pop();
		if(mx < que.top()) {
			mi=i; mx=que.top();
		}
		ord[que.top().idx]=i;
		use[que.top().idx]=1;
		
		int idx=que.top().idx;
		que.pop();
		for(auto &it:adj[idx]) if(!use[it]) {
			rem[it]--;
			que.push(frac(rem[it],cnt[it],it));
		}
	}
	printf("%d\n",n-k-mi+1);
	for(int i=1;i<=n;i++) if(ord[i]>=mi) {
		printf("%d ",i);
	}
	
	return 0;
}