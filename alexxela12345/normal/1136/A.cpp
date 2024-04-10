#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
	cin >> arr[i].first >> arr[i].second;
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
	if (arr[i].first <= k && arr[i].second >= k) {
	    cout << n - i << endl;
	    return 0;
	}
    }
    assert(false);

    return 0;
}