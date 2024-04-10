#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double rl;

int n;
ll r;
ll l[ 2 * 100009 ], t[ 2 * 100009 ];

ll K;
vector< ll > answ;

void Solve( bool save )
{
    ll p = 0;
    ll T = 0;

    for ( int i=0; i<n; i++ )
    {
        ll patl = min( p, l[ i ] );
        ll t_l = l[ i ] - patl;
        ll t_t = t[ i ] - patl;
        T += patl;

        p -= patl;

        if ( t_t < 0 )  // NEATLIEK LAIKS
        {
            K = -1;
            return;
        }

        if ( t_l == 0 )
        {
            continue; // VISS PARKLAJAS
        }

        ll x = max( 2*t_l - t_t, 0LL );
        ll y = t_l - x;
        if ( x<0 || y<0 || x+2*y > t_t )
        {
            K = -1;
            return; // NAV IESPEJAMS
        }

        T += 2*y;
        ll cnt = ( x + r - 1 )/ r;

        if ( save )
        {
            for ( int i=0; i<cnt; i++ )
            {
                answ.push_back( T + i * r );
            }
        }

        T += x;

        K += cnt;
        p = ( cnt * r ) - x;
    }
}

int main()
{
    scanf("%d %lld", &n, &r );

    for ( int i=0; i<n; i++ )
        scanf("%lld", &l[ i ] );

    for ( int i=0; i<n; i++ )
        scanf("%lld", &t[ i ] );

    K = 0;
    Solve( false );

    printf("%lld\n", K );
    if ( K <= 100000 && K != -1 )
    {
        K = 0;
        Solve( true );
        for ( size_t i = 0 ; i<answ.size(); i++ )
            printf("%lld ", answ[ i ] );
        printf("\n");
    }

    return 0;
}