#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> P;
int						num[400005], q, x;
priority_queue < P, vector<P>, greater<P> >	que; /* num,id. */
int main()
{
	scanf( "%d%d", &q, &x );
	for ( int i = 0; i < x; i++ )
		que.push( mp( num[i], i ) );
	for ( int i = 1; i <= q; i++ )
	{
		int y;
		scanf( "%d", &y );
		y %= x;
		num[y]++;
		que.push( mp( num[y], y ) );
		while ( true )
		{
			P p = que.top();
			if ( num[p.second] == p.first )
			{
				printf( "%d\n", p.first * x + p.second );
				break;
			}
			que.pop();
		}
	}
	return(0);
}