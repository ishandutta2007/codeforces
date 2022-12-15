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

int n;
vector<int> adj[100001];

int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int c=0,ct;
	vector<int> cand;
	for(int i=1;i<=n;i++) {
		if(adj[i].size()==1) cand.push_back(i);
		else if(adj[i].size()>=3) {
			if(c==1) {
				puts("No");
				return 0;
			}
			c=1;
			ct=i;
		}
	}
	puts("Yes");
	if(cand.size()%2==0) {
		printf("%d\n",cand.size()/2);
		for(int i=0;i<cand.size();i+=2) {
			printf("%d %d\n",cand[i],cand[i+1]);
		}
	}
	else {
		printf("%d\n",cand.size());
		for(int i=0;i<cand.size();i++) 
			printf("%d %d\n",ct,cand[i]);
	}
	
	return 0;
}