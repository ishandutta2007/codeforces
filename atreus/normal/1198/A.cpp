#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 4e5 + 10;

int a[maxn], LOG[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, I;
	cin >> n >> I;
	vector<int> v;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	LOG[1] = 0;
	for (int i = 2; i <= n; i++)
		LOG[i] = LOG[(i + 1) >> 1] + 1;
	sort(a, a + n);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	I *= 8;
	int answer = n;
	for (int i = 0; i < n; i++){
		int lo = i - 1, hi = n;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			int y = lower_bound(v.begin(), v.end(), a[mid]) - v.begin();
			int num = y - x + 1;
			if (LOG[num] * n <= I)
				lo = mid;
			else
				hi = mid;
		}
		answer = min(answer, i + (n - lo - 1));
	}
	cout << answer << endl;
}