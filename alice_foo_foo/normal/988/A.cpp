#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int ans[N], len = 0;
int a[N];
bool used[N];
int n, k;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(used[a[i]] == 0 && len != k) {
			ans[++len] = i;
			used[a[i]] = 1;
		}
	}
	if(len != k) cout << "NO";
	else {
		cout << "YES" << endl;
		for(int i = 1; i <= k; i++) cout << ans[i] << " ";
	}
	return 0;
}