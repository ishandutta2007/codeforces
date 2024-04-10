#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) {
	cin >> a1[i];
    }
    for (int i = 0; i < n; i++) {
	cin >> a2[i];
    }
    map<int, map<int, int>> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
	int a = a1[i], b = a2[i];
	if (b == 0 && a == 0) {
	    cnt++;
	} else if (a != 0) {
	    int g = __gcd(a, b);
	    a /= g;
	    b /= g;
	    m[a][b]++;
	}
    }
    int maxx = 0;
    for (auto el : m) {
	for (auto el2 : el.second) {
	    maxx = max(maxx, el2.second);
	}
    }
    cout << maxx + cnt << endl;
    

    return 0;
}