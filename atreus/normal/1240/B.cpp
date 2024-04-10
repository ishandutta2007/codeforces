#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;

int a[maxn], pre[maxn], first[maxn], last[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		vector<int> cmp;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			cmp.push_back(a[i]);
		}
		sort(cmp.begin(), cmp.end());
		cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
		for (int i = 1; i <= n; i++)
			a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
		for (int i = 1; i <= n; i++)
			last[a[i]] = i;
		for (int i = n; i >= 1; i--)
			first[a[i]] = i;
		int m = cmp.size();
		pre[1] = 1;
		int answer = m - 1;
		for (int i = 2; i <= m; i++){
			if (last[i - 1] < first[i])
				pre[i] = pre[i - 1];
			else
				pre[i] = i;
			answer = min(answer, m - (i - pre[i] + 1));
		}
		cout << answer << endl;
	}
}