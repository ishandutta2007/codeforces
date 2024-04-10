#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;
	vector<pair<int,int>> ops;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		ops.push_back({x * a + y * b, i});
	}
	sort(ops.begin(), ops.end());
	vector<int> ans;
	for (auto it : ops){
		if (it.first <= d){
			ans.push_back(it.second);
			d -= it.first;
		}
	}
	cout << ans.size() << endl;
	for (auto it : ans)
		cout << it << " ";
	cout << endl;
}