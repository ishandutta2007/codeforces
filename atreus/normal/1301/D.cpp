#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;
const int inf = 2e9;

int k;
vector<pair<int, string>> ops;

void go(string s, int f){
	if (k == 0 or f == 0)
		return;
	if (f * (int)s.size() <= k){
		ops.push_back({f, s});
		k -= f * (int)s.size();
		return;
	}
	int sz = (int)s.size();
	if (k >= sz)
		ops.push_back({k / sz, s});
	k %= sz;
	if (k > 0)
		ops.push_back({1, s.substr(0, k)});
	k = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> k;
	if (k > 4*n*m - 2*n - 2*m){
		cout << "NO\n";
		return 0;
	}
	if (m == 1){
		go("D", n-1);
		go("U", n-1);
	}
	else{
		for (int i = 1; i < n; i++){
			go("R", 1);
			go("DUR", m - 2);
			go("DUL", 1);
			go("L", m - 2);
			go("D", 1);
		}
		go("R", m-1);
		go("L", m-1);
		go("U", n-1);
	}
	cout << "YES\n";
	cout << ops.size() << '\n';
	for (auto it : ops)
		cout << it.first << " " << it.second << '\n';
}