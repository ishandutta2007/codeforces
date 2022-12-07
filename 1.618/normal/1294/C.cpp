#include <bits/stdc++.h>
using namespace std;
int		t, n;
vector <int>	fac;
void print( int a, int b )
{
	printf( "YES\n%d %d %d\n", a, b, n / a / b );
}


int main()
{
	scanf( "%d", &t );
	while ( t-- )
	{
		scanf( "%d", &n );
		int tot = 0, x = n;
		fac.clear();
		for ( int i = 2; i * i <= x; i++ )
		{
			if ( x % i == 0 )
			{
				fac.push_back( i );
				while ( x % i == 0 )
				{
					tot++;
					x /= i;
				}
			}
		}
		if ( x > 1 )
		{
			fac.push_back( x );
			tot++;
			x = 1;
		}
		if ( fac.size() == 1 )
		{
			if ( tot <= 5 )
				puts( "NO" );
			else print( fac[0], fac[0] * fac[0] );
		}else if ( fac.size() == 2 )
		{
			if ( tot <= 3 )
				puts( "NO" );
			else print( fac[0], fac[1] );
		}else{
			print( fac[0], fac[1] );
		}
	}
	return(0);
}