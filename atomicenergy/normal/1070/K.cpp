#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int b[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	long long a = 0;
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		a += b[i];
	}
	if(a % k != 0) {
		cout << "No\n";
		return 0;
	}
	int psum = 0;
	int hit = 0;
	int len = 0;
	vector<int> ans;
	for(int i = 0; i < n; ++i) {
		psum += b[i];
		++len;
		if(psum == a/k) {
			ans.push_back(len);
			psum = 0;
			len = 0;
			++hit;
		}
	}
	if(hit == k) {
		cout << "Yes\n";
		for(int x : ans)
			cout << x << " ";
		cout << "\n";
	} else {
		cout << "No\n";
	}
}