#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c[n];
    int t[n];
    int C[n - 1], T[n - 1];
    for(int i = 0; i < n; i++) {
		cin >> c[i];
		if(i > 0) {
			C[i - 1] = c[i] - c[i - 1];
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
		if(i > 0) {
			T[i - 1] = t[i] - t[i - 1];
		}
	}
	sort(C, C + n - 1);
	sort(T, T + n - 1);
	
	if(c[0] == t[0] && memcmp(C, T, (n - 1) * sizeof(int)) == 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
    return 0;
}