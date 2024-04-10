#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define pii pair<int,int>
#define mp make_pair

vector <int> nums[100001];
int n,m;

pii bfs (int a) {
	bool is[n];
	fop (i,0,n) is[i] = true;
	pii ans;
	queue <pii> nn;
	is[a] = false;
	fop (i,0,nums[a].size()) {
		nn.push(mp(nums[a][i],1));
		is[nums[a][i]] = false;
	}
	while (nn.size())  {
		int k,b;
		ans = nn.front();
		tie(k,b) = ans;
		nn.pop();
		fop (i,0,nums[k].size()) {
			if (is[nums[k][i]]) {
				nn.push(mp(nums[k][i],b+1));
			}
			is[nums[k][i]] = false;
		}
	}
	return ans;
}




int main () {
	int a,b;
	cin >> n >> m;
	fop(i,0,m) {
		cin >> a >> b;
		nums[a-1].push_back(b-1);
		nums[b-1].push_back(a-1);
	}
	pii c = bfs(0);
	cout << bfs(c.first).second << endl;
}