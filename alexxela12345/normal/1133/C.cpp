#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int r = 0;
    int max_ans = 1;
    for (int l = 0; l < n; l++) {
	while (r < n - 1 && arr[r + 1] - arr[l] <= 5) {
	    r++;
	}
	max_ans = max(max_ans, r - l + 1);
    }
    cout << max_ans << endl;

    return 0;
}