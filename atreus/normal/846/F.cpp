#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e6 + 10;

int a[maxn];
vector<int> v[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	ll answer = 0;
	for (int i = 1; i <= 1000000; i++){
		if (v[i].empty())
			continue;
		v[i].push_back(n + 1);
		answer += 1ll * n * n;
		for (int j = 0; j < v[i].size(); j++){
			int len = v[i][j] - (j == 0 ? 0 : v[i][j - 1]) - 1;
			answer -= 1ll * len * len;
		}
	}
	cout << fixed << setprecision(6) << 1. * answer / (1ll * n * n) << endl;
}