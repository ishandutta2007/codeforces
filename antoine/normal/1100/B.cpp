#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int occ[(int) 1e5 + 9];
int cnt = 0;

void add(int i, int x) {
	cnt -= occ[i] != 0;
	occ[i] += x;
	cnt += occ[i] != 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		{
			int x;
			cin >> x;
			add(x, 1);
		}
		if(cnt != n)
			cout << 0;
		else {
			cout << 1;
			for(int i = 1; i <= n; ++i)
				add(i, -1);
		}
	}

	return 0;
}