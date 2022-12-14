#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
int x[maxn], y[maxn];
bool mark[1010][1010];

int adjx[] = {+1, +1, +1, 0, 0, 0, -1, -1, -1};
int adjy[] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};

bool check(int t){
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= t; i++)
		mark[x[i]][y[i]] = 1;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++){
			bool flag = 1;
			for (int z = 0; z < 9; z++)
				flag &= mark[i + adjx[z]][j + adjy[z]];
			if (flag)
				return 1;
		}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> x[i] >> y[i];
	int lo = 8, hi = m + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	if (hi == m + 1)
		hi = -1;
	cout << hi << endl;
}