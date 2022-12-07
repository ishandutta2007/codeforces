#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int			n, m;
vector < vector<int> >	a;
int			ans[maxn << 1];
int solve( int c ) /* column: c. */
{
	for ( int i = 1; i <= n; i++ )
		ans[i] = n + i - 1;
	for ( int i = 1; i <= n; i++ )
		if ( a[i][c] <= n * m && a[i][c] % m == c % m )
		{
			int p = ( (i - 1) * m + c) / m, q = a[i][c] / m;
			if ( p >= q )
				ans[1 + p - q]--;
			else ans[1 + p + n - q]--;
		}
	int res = n;
	for ( int i = 1; i <= n; i++ )
	{
		res = min( res, ans[i] );
	}
	return(res);
}


int main()
{
	scanf( "%d%d", &n, &m );
	a.resize( n + 5 );
	for ( int i = 1; i <= n; i++ )
		a[i].resize( m + 5 );
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			scanf( "%d", &a[i][j] );
		}
	}
	int res = 0;
	for ( int i = 1; i <= m; i++ )
		res += solve( i );
	printf( "%d\n", res );
	return(0);
}