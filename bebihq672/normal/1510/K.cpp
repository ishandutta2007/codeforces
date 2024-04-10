#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
const int INF = 0x3f3f3f3f;
int _w;

int n, a[N*2], p[N*2];

bool ok() {
	for( int i = 1; i <= n+n; ++i )
		if( a[i] != p[i] )
			return false;
	return true;
}

bool fail() {
	for( int i = 1; i <= n+n; ++i )
		if( a[i] != i )
			return false;
	return true;
}

void op1() {
	for( int i = 1; i <= n+n; i += 2 )
		swap( a[i], a[i+1] );
}

void op2() {
	for( int i = 1; i <= n; ++i )
		swap( a[i], a[i+n] );
}

int solve1() {
	for( int i = 1; i <= n+n; ++i )
		a[i] = i;
	int ans = 0;
	while(1) {
		if( ok() ) return ans;
		if( fail() && ans ) return INF;
		op1(), ++ans;
		if( ok() ) return ans;
		if( fail() && ans ) return INF;
		op2(), ++ans;
	}
}

int solve2() {
	for( int i = 1; i <= n+n; ++i )
		a[i] = i;
	int ans = 0;
	while(1) {
		if( ok() ) return ans;
		if( fail() && ans ) return INF;
		op2(), ++ans;
		if( ok() ) return ans;
		if( fail() && ans ) return INF;
		op1(), ++ans;
	}
}

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n+n; ++i )
		_w = scanf( "%d", p+i );
	int ans = min( solve1(), solve2() );
	printf( "%d\n", ans == INF ? -1 : ans );
	return 0;
}