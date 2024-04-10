#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;

int l[maxn], r[maxn], a[2 * maxn], light[2 * maxn], b[2 * maxn]; 

void solve(){
	int n;
	cin >> n;
	vector<int> c;
	for (int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		c.push_back(l[i]);
		c.push_back(r[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for (int i = 1; i <= n; i++){
		l[i] = lower_bound(c.begin(), c.end(), l[i]) - c.begin() + 1;
		r[i] = lower_bound(c.begin(), c.end(), r[i]) - c.begin() + 1;
	}
	int m = c.size();
	for (int i = 1; i <= m; i++){
		a[i] = 0;
		b[i] = 0;
		light[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		a[l[i]] ++;
		a[r[i]+1] --;
		b[l[i]] ++;
	}
	for (int i = 1; i <= m; i++)
		a[i] += a[i - 1];
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		if (a[i] == b[i] and a[i] > 0)
			cnt ++;

	for (int i = 1; i <= m; i++)
		if (a[i] == b[i] + 1 and b[i] > 0)
			light[i] ++;
	
	for (int i = 2; i <= m; i++)
		light[i] += light[i - 1];

	int answer = 0;
	for (int i = 1; i <= n; i++){
		int now = cnt + light[r[i]] - light[l[i]];
		if (a[l[i]] == b[l[i]] and a[l[i]] == 1)
			now --;
		answer = max(answer, now);
	}
	cout << answer << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}