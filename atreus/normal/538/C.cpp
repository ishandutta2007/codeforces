#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1e5 + 10;
const int inf = 3e5;

int d[maxn], h[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> d[i] >> h[i];
	int answer = max(h[1] + (d[1] - 1), h[m] + (n - d[m]));
	for (int i = 1; i <= m-1; i++){
		if (abs(h[i+1]-h[i]) > d[i+1]-d[i])
			return cout << "IMPOSSIBLE\n", 0;
		int diff = d[i+1]-d[i] - abs(h[i+1]-h[i]);
		answer = max(answer, max(h[i],h[i+1]) + diff/2);
	}
	cout << answer << '\n';
}