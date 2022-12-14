#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn], dp[maxn], rig[maxn], lef[maxn];

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	lef[0] = 1;
	for (int i = 1; i < n; i++){
		if (a[i] > a[i - 1])
			lef[i] = lef[i - 1] + 1;
		else
			lef[i] = 1;
	}
	rig[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--){
		if (a[i] < a[i + 1])
			rig[i] = rig[i + 1] + 1;
		else
			rig[i] = 1;

	}
	int k = 0;
	for (int i = 0; i < n; i++){
		if (i != 0 && a[i + 1] - a[i - 1] >= 2)
			dp[i] = lef[i - 1] + rig[i + 1] + 1;
		else if (i != 0)
			dp[i] = max(rig[i + 1] + 1, lef[i - 1] + 1);
		else
			dp[i] = max(rig[i + 1] + 1, rig[i]);
		k = max(k, dp[i]);
	}
	cout << k << endl;
}