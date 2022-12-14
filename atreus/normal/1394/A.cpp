#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	int n, d, m;
	cin >> n >> d >> m;
	vector<int> a, b;
	ll now = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x <= m)
			a.push_back(x), now += x;
		else
			b.push_back(x);
	}
	sort(b.rbegin(), b.rend());
	sort(a.begin(), a.end());
	ll answer = now;
	int ptr = 0;
	ll pre = 0;
	for (int i = 0; i < b.size(); i++){
		int t = 1LL*i*d - ((int)b.size() - i-1);
		if (t > (int)a.size())
			break;
		pre += b[i];
		while (ptr < t)
			now -= a[ptr++];
		answer = max(answer, now + pre);
	}
	cout << answer << endl;
}