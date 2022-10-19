#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sp ' '
#define fi first
#define se second

bool check[200005];
int n;
string s;

void prepare(int k) {
	if (n % k != 0) {
		check[k] = false;
		return;
	}
	bool flag = true;
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		for (int j = i; j < n; j += k) {
			cnt += (s[j] == '1');
		}
		if (cnt % 2 == 1) {
			flag = false;
			break;
		}
	}
	check[k] = flag;
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		prepare(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += check[__gcd(i, n)];
	}
	cout << ans;
	return 0;
}