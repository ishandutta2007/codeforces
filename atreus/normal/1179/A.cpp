#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;

int a[maxn];
pair<int, int> ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	deque<int> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		d.push_back(a[i]);
	}
	int idx = max_element(a + 1, a + n + 1) - a;
	for (int i = 1; i <= idx; i++){
		int A = d.front();
		d.pop_front();
		int B = d.front();
		ans[i] = {A, B};
		d.pop_front();
		if (A > B)
			swap(A, B);
		d.push_back(A);
		d.push_front(B);
	}
	for (int i = 1; i <= n; i++){
		a[i] = d.front();
		d.pop_front();
	}
	for (int i = 0; i < q; i++){
		ll m;
		cin >> m;
		if (m <= idx){
			cout << ans[m].first << " " << ans[m].second << '\n';
			continue;
		}
		m -= idx;
		m %= (n - 1);
		if (m == 0)
			m = n - 1;
		cout << a[1] << " " << a[m + 1] << '\n';
	}
}