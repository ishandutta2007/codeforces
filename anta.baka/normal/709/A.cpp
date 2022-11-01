#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, b, d;
	cin >> n >> b >> d;
	int cnt = 0;
	long long siz = 0;
	for(int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if(v > b)
			continue;
		siz += v;
		if(siz > d) {
			siz = 0;
			cnt++;
		}
	}
	cout << cnt;
}