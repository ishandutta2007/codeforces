#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=2e5+7;
struct dp {
	long long wierz, sum, ma;
};
vector<int>V[LIM];
long long wart[LIM];
dp DFS(int x) {
	dp ans; ans.sum=wart[x]; ans.ma=0; ans.wierz=0;
	if(V[x].size()==0) {
		++ans.wierz;
		ans.ma=wart[x];
	}
	for(auto i : V[x]) {
		dp pom=DFS(i);
		ans.sum+=pom.sum;
		ans.ma=max(ans.ma, pom.ma);
		ans.wierz+=pom.wierz;
	}
	ans.ma=max(ans.ma, (ans.sum+ans.wierz-1)/ans.wierz);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n-1) {
		int a;
		cin >> a; --a;
		V[a].push_back(i+1);
	}
	rep(i, n) cin >> wart[i];
	dp ans=DFS(0);
	cout << ans.ma;
}