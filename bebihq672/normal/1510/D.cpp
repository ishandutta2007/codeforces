#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int N = 100010;
const double INFD = 1e100;
int _w;

int n, d, a[N];

double f[N][10];
pii g[N][10];

void solve() {
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < 10; ++j ) {
			f[i][j] = -INFD;
			g[i][j] = pii(-1, -1);
		}
	for( int i = 1; i <= n; ++i )
		f[i][a[i] % 10] = log( a[i] );
	for( int i = 1; i < n; ++i )
		for( int j = 0; j < 10; ++j ) {
			if( f[i][j] > f[i+1][j] ) {
				f[i+1][j] = f[i][j];
				g[i+1][j] = pii(0, j);
			}
			int x = a[i+1];
			int nj = j * x % 10;
			if( f[i][j] + log(x) > f[i+1][nj] ) {
				f[i+1][nj] = f[i][j] + log(x);
				g[i+1][nj] = pii(1, j);
			}
		}
	if( f[n][d] < -100 ) {
		puts("-1");
		return;
	}
	vector<int> ans;
	int i = n;
	int j = d;
	while( j != -1 ) {
		if( g[i][j].first )
			ans.push_back( a[i] );
		j = g[i][j].second;
		i--;
	}
	printf( "%d\n", (int)ans.size() );
	sort(ans.begin(), ans.end());
	for( int i = 0; i < (int)ans.size(); ++i ) {
		if( i ) putchar(' ');
		printf( "%d", ans[i] );
	}
	puts("");
}

int main() {
	_w = scanf( "%d%d", &n, &d );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", a+i );
	solve();
	return 0;
}