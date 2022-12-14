#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 50;

int a[maxn], b[maxn];
map<pair<int, int>, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
		sum += b[i];
	}
	int q;
	cin >> q;
	while (q --){
		int s, t, u;
		cin >> s >> t >> u;
		if (mp[{s, t}] != 0){
			int idx = mp[{s, t}];
			sum -= max(0, b[idx]);
			b[idx] ++;
			sum += max(0, b[idx]);
		}
		if (u != 0){
			sum -= max(0, b[u]);
			b[u] --;
			sum += max(0, b[u]);
		}
		mp[{s, t}] = u;
		cout << max(1ll, sum) << '\n';
	}
}