#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 100 * 1000 + 5;

pair <pair <int, int>, int> a[N];
int dp[N];
int ans[N];
stack <int> st;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i; i--) {
		dp[i] = i;
		while (st.size() && a[i].first.first + a[i].first.second > a[st.top()].first.first) {
		//	cout << "73 " << i << " " << st.top() << endl;
			dp[i] = max(dp[i], dp[st.top()]);
			st.pop();
		}
		st.push(i);
		ans[a[i].second] = dp[i] - i + 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}