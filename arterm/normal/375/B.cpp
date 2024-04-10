#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 5050

int n, m;

string s[M];
int d[M][M],t[M];

void read(void){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
}

void pre(void){
	for (int i = 0; i < n; ++i)
	for (int j = m - 1; j >= 0; --j)
	if (s[i][j] == '1')
		d[i][j] = 1 + d[i][j + 1];
}


void kill(void){
	int ans = 0;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			t[j] = d[j][i];
		sort(t, t + n);
		for (int k = 1; i + k <= m; ++k)
			ans = max(ans, k*((t + n) - lower_bound(t, t + n, k)));
	}
	cout << ans << "\n";
}

int main(){
#ifdef TROLL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	pre();
	kill();


	return 0;
}