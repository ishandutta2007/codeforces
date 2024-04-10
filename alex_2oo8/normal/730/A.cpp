#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double rl;

int n;

struct Spel{
    int id, r;
    bool operator<( const Spel& rhs )const
    {
        return ( r != rhs.r ) ? r > rhs.r : id < rhs.id;
    }
}s[ 109 ];

int cntA;
vector< int > answ[ 10009 ];

int cnt[ 109 ];
set< Spel > ss;
char an[ 109 ];

int main()
{
    scanf("%d", &n );
    for ( int i=0; i<n; i++ )
    {
        scanf("%d", &s[ i ].r );
        s[ i ].id = i;
        cnt[ s[ i ].r ]++;

        ss.insert( s[ i ] );
    }

    int Ransw;
    while ( true )
    {
        auto it = ss.begin();

        if ( cnt[ it->r ] == n )
        {
            Ransw = it->r;
            break;
        }
        else if ( cnt[ it->r ] == 3 )
        {
            for ( int i=0; i<3; i++ )
            {
                Spel tmp = *it;
                ss.erase( it );

                cnt[ tmp.r ]--;
                tmp.r = max( tmp.r-1, 0 );
                cnt[ tmp.r ]++;

                answ[ cntA ].push_back( tmp.id );
                ss.insert( tmp );

                it = ss.begin();
            }
            cntA++;
        }
        else
        {
            Spel tmpa, tmpb;
            tmpa = *it;
            ss.erase( it );
            tmpb = *ss.begin();
            ss.erase( ss.begin() );

            cnt[ tmpa.r ]--;
            cnt[ tmpb.r ]--;
            tmpa.r = max( tmpa.r-1, 0 );
            tmpb.r = max( tmpb.r-1, 0 );
            cnt[ tmpa.r ]++;
            cnt[ tmpb.r ]++;
            ss.insert( tmpa );
            ss.insert( tmpb );

            answ[ cntA ].push_back( tmpa.id );
            answ[ cntA ].push_back( tmpb.id );

            cntA++;
        }
    }

    printf("%d\n", Ransw );
    printf("%d\n", cntA );
    for ( int i=0; i<cntA; i++ )
    {
        for ( int i=0; i<n; i++ )
            an[ i ] = '0';

        for ( auto it : answ[ i ] )
            an[ it ] = '1';

        for ( int i=0; i<n; i++ )
            printf("%c", an[ i ] );
        printf("\n");
    }

    return 0;
}