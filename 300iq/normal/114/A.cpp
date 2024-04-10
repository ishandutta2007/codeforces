#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k, l, p;
    cin >> k >> l;
    int cnt = 0;
    if (l == k) {
	cout << "YES" << endl << 0 << endl;
	return 0;
    }
    p = 1;
    while (p <= l) {
	p *= k;
	if (p == l) {
	    cout << "YES" << endl << cnt << endl;
	    return 0;
	}
	cnt++;
    }
    cout << "NO" << endl;
    return 0;
}