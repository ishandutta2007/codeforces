#include <bits/stdc++.h>
#define maxn	1005
#define mp	make_pair
using namespace std;
typedef pair<int, int> P;
int	t, n;
P	ps[maxn];
void solve()
{
	scanf( "%d", &n );
	for ( int i = 1; i <= n; i++ )
	{
		scanf( "%d%d", &ps[i].first, &ps[i].second );
	}
	sort( ps + 1, ps + n + 1 );
	for ( int i = 1; i <= n; i++ )
	{
		if ( ps[i].second < ps[i - 1].second )
		{
			puts( "NO" );
			return;
		}
	}
	puts( "YES" );
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = ps[i - 1].first; j < ps[i].first; j++ )
			printf( "R" );
		for ( int j = ps[i - 1].second; j < ps[i].second; j++ )
			printf( "U" );
	}
	puts( "" );
}


int main()
{
	scanf( "%d", &t );
	while ( t-- )
		solve();
	return(0);
}