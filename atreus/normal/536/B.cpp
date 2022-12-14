#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;

int y[maxn], f[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string p;
	cin >> p;
	for (int i = 0; i < m; i++)
		cin >> y[i];

	int cur = 0;
	for (int i = 1; i < p.size(); i++){
		while (cur != 0 and p[i] != p[cur]){
			cur = f[cur];
		}
		if (p[i] == p[cur])
			cur ++;
		f[i + 1] = cur;
	}
	int x = f[p.size()];
	while (x != 0){
		mark[x] = 1;
		x = f[x];
	}
	
	for (int i = 1; i < m; i++){
		if (y[i] - y[i - 1] >= p.size())
			continue;
		int diff = y[i] - y[i - 1];
		if (!mark[p.size() - diff])
			return cout << 0 << endl, 0;
	}

	ll ans = 1;
	for (int i = 1; i <= n; i++){
		int idx = upper_bound(y, y + m, i) - y;
		idx --;
		if (idx < 0 or y[idx] + p.size() - 1 < i){
			ans = ans * 26 % mod;
		}
	}
	cout << ans << endl;
}