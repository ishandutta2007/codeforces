#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

int v[4000],d[4000],p[4000],n;

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d%d",v+i,d+i,p+i);

	vector<int> ans;
	queue<int> ci;
	for(int i=0;i<n;i++) {
		while(!ci.empty()) {
			int ii=ci.front(); ci.pop();
			for(int j=ii+1;j<n;j++) if(p[j]>=0) {
				p[j] -= d[ii];
				if(p[j]<0) ci.push(j);
			}
		}
		if(p[i]<0) continue;
		ans.push_back(i+1);
		
		int val=v[i];
		for(int j=i+1;j<n && val;j++) if(p[j]>=0) {
			p[j] -= val;
			val--;
			if(p[j]<0) ci.push(j);
		}
	}
	printf("%d\n",sz(ans));
	for(auto &val:ans) printf("%d ",val);
	return 0;
}