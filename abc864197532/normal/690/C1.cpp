#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)

pair <int,int> nums[1001];
vector <int> push[1001];
int n,m;
bool is[1001];

void dfs(int k,int t) {
	is[k]=true;
	fop(i,0,push[k].size()) {
		if (t!=-1) {
			if (push[k][i]==nums[t].first and k==nums[t].second) continue;
			if (push[k][i]==nums[t].second and k==nums[t].first) continue;
		}
		if (!is[push[k][i]]) {
			is[push[k][i]]=true;
			dfs(push[k][i],t);
		}
	}
}


bool let(int t) {
	fop (i,1,n+1) {
		dfs(i,t);
		fop(j,1,n+1) {
			if (!is[j]) return false;
			is[j]=false;
		}
	}
	return true;
}



int main () {
	int a,b;
	cin >> n >> m;
	fop(i,0,m) {
		cin >> a >> b;
		nums[i]=make_pair(a,b);
		push[a].push_back(b);
		push[b].push_back(a);
	}
	if (let(-1)) {
		fop (i,0,m) {
			if (let(i)) {
				cout << "no" << endl;
				return 0;
			}
		}
		cout << "yes" << endl;
		return 0;
	} else {
		cout << "no" << endl;
		return 0;
	}
}