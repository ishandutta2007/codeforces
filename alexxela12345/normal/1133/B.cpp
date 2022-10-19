#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    map<int, int> m;
    for (int i = 0; i < n; i++) {
	m[a[i] % k]++;
    }
    int cnt = 0;
    for (int i = 1; i < k - i; i++) {
	cnt += min(m[i], m[k - i]) * 2;
    }
    cnt += m[0] / 2 * 2;
    if (k % 2 == 0) {
	cnt += m[k / 2] / 2 * 2;
    }
    cout << cnt << endl;
    return 0;
}