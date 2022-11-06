#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int w, h;
	cin >> w >> h;

	int u[2], d[2];
	cin >> u[0] >> d[0] >> u[1] >> d[1];

	for(; h > 0; --h) {
		w += h;
		for(int i = 0; i < 2; ++i)
			if(h == d[i]) {
				w -= u[i];
				if(w < 0)
					w = 0;
			}
	}
	cout << w;
	return 0;
}