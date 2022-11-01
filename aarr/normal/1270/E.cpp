#include <iostream>
#include <vector>
#define int long long
using namespace std;


const int N = 1005;
const long long inf = 1000ll * 1000 * 1000 * 1000 * 100 + 7;
int n;

vector <int> vec;
int x[N];
int y[N];
bool mark[N];
long long dis(int a, int b) {
	long long ans = 1ll * (x[a] - x[b]) * (x[a] - x[b]);
	ans += 1ll * (y[a] - y[b]) * (y[a] - y[b]);
	return ans;
}
void dfs(int v, long long z) {
	if (mark[v]) {
		return;
	}
	mark[v] = true;
	vec.push_back(v);
	for (int i = 1; i <= n; i++) {
		if (i != v && dis(i, v) % z == 0) {
			dfs(i, z);
		}
	}
} 
int32_t main() {
	cin >> n;
	int maxi = 0;
//	int minx = inf, miny = inf;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
//	cout << "73 " << minx << " " << miny << endl;
	for (long long i = 2; i <= inf; i *= 2) {
		vec.clear();
	//	cout << "73 " << i << endl;
		fill(mark, mark + n + 1, false);
		dfs(1, i);
	//	cout << "73 " << i << " " << vec.size() << endl;
		if (vec.size() != n) {
			cout << vec.size() << endl;
			for (auto u : vec) {
				cout << u << " ";
			}
			return 0;
		}
	}
	return 0;
}