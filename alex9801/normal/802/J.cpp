#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 100005;

vector<pi> gph[MAXN];
int n;

int dfs(int x, int p){
	int ret = 0;
	for(auto &i : gph[x]){
		if(i.second != p){
			ret = max(ret, i.first + dfs(i.second, x));
		}
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int s, e, x;
		cin >> s >> e >> x;
		gph[s].push_back(pi(x, e));
		gph[e].push_back(pi(x, s));
	}
	cout << dfs(0, -1);
}