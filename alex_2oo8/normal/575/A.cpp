#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <deque>
#include <set>
using namespace std;
const int MAXN = 50010;
const int leet = 1337;
const int bredor = 228;
const int inf = 1000000001;
long long modulo;

struct Matrix
{
    long long a[2][2];
};

Matrix I;

Matrix operator *( Matrix A , Matrix B )
{
    Matrix C;
    C.a[0][0] = ( A.a[0][0] * B.a[0][0] + A.a[0][1] * B.a[1][0] ) % modulo;
    C.a[0][1] = ( A.a[0][0] * B.a[0][1] + A.a[0][1] * B.a[1][1] ) % modulo;
    C.a[1][0] = ( A.a[1][0] * B.a[0][0] + A.a[1][1] * B.a[1][0] ) % modulo;
    C.a[1][1] = ( A.a[1][0] * B.a[0][1] + A.a[1][1] * B.a[1][1] ) % modulo;
    return C;
}

void print( Matrix A )
{
    cout << A.a[0][0] << " " << A.a[0][1] << endl;
    cout << A.a[1][0] << " " << A.a[1][1] << endl;
}

Matrix pow( Matrix A , long long x )
{
    if ( x == 0 ) return I;
    Matrix R = pow( A , x / 2 );
    R = R * R;

    if ( x % 2 == 1 ) R = A * R;
    return R;
}

long long s[MAXN];
pair< long long , long long > a[MAXN];
Matrix tree[4 * MAXN];


void build_tree( int v , int tl , int tr )
{
    if ( tl == tr )
    {
        tree[v].a[0][0] = s[ tl ];
        tree[v].a[0][1] = s[ tl - 1 ];
        tree[v].a[1][0] = 1;
        tree[v].a[1][1] = 0;
    }
    else
    {
        int mid = ( tl + tr ) / 2;
        build_tree( 2 * v , tl , mid );
        build_tree( 2 * v + 1 , mid + 1 , tr );
        tree[v] = tree[2 * v + 1] * tree[2 * v];
    }
    //cout << "Interval: [ " << tl << " : " << tr << "]" << endl;
    //print( tree[v] );
}

void Modify( int v , int tl , int tr , int pos )
{
    if ( tl == tr )
    {
        tree[v].a[0][0] = s[ tl ];
        tree[v].a[0][1] = s[ tl - 1 ];
        tree[v].a[1][0] = 1;
        tree[v].a[1][1] = 0;
    }
    else
    {
        int mid = ( tl + tr ) / 2;

        if ( pos <= mid )
            Modify( 2 * v , tl , mid , pos );
        else
            Modify( 2 * v + 1 , mid + 1 , tr , pos );

        tree[v] = tree[2 * v + 1] * tree[2 * v];
    }
}

Matrix getMatrix( int v , int tl, int tr , int l , int r )
{
    if ( l > r ) return I;
    if ( tl > r || l > tr ) return I;
    l = max( l , tl );
    r = min( r , tr );

    if ( tl == l && tr == r ) return tree[v];

    int mid = ( tl + tr ) / 2;
    return getMatrix( 2 * v + 1 , mid + 1 , tr , l , r  ) * getMatrix( 2 * v , tl , mid , l , r );
}

void ModifyTree( int idx , int N )
{
    Modify( 1 , 1 , N , idx + 1 );
    if ( idx != 0 )
        Modify( 1 , 1 , N , idx );
}

vector < pair< long long , long long > > Changes;
int main()
{
    //freopen("input.in", "r", stdin);
    long long K;
    cin >> K >> modulo;

    long long N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> s[i];
    s[N] = s[0];

    if ( N == 1 )
    {
        N = 2;
        s[2] = s[0];
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
        cin >> a[i].first >> a[i].second;

    build_tree( 1 , 1 , N );

    sort( a , a + M );

    while ( M > 0 && a[M - 1].first >= K ) M--;
    M++;
    a[ M - 1 ].first = K;
    a[ M - 1 ].second = s[ K % N ];

    int pnt = 0;
    long long prevBlock = 0;

    Matrix R;
    R.a[0][0] = R.a[1][1] = 1;
    R.a[0][1] = R.a[1][0] = 0;
    I = R;

    while ( pnt < M )
    {
        long long currBlock = (a[pnt].first / N) + 1;
        if ( currBlock - prevBlock - 1 >= 1 )
        {
            R = pow( tree[1] , currBlock - prevBlock - 2) * R;
            long long Last = -1;
            if ( a[pnt].first == currBlock * N - N )
            {
                Last = s[N];
                s[ N ] = a[pnt].second;
                ModifyTree( N - 1 , N );
            }
            R = tree[1] * R;
            if ( a[pnt].first == currBlock * N - N )
            {
                s[N] = Last;
                ModifyTree( N - 1 , N );
            }
        }
        Changes.clear();

        while ( pnt < M && ( a[pnt].first / N ) + 1 == currBlock )
        {
            Changes.push_back( a[pnt] );
            pnt++;
        }

        for (int i = 0; i < Changes.size(); i++)
        {
            long long w = s[ Changes[i].first % N  ];
            s[ Changes[i].first % N  ] = Changes[i].second;
            Changes[i].second = w;
            ModifyTree( Changes[i].first % N , N );
        }

        long long Last = -1;
        if ( pnt < M && a[pnt].first == currBlock * N )
        {
            Last = s[N];
            s[ N ] = a[pnt].second;
            ModifyTree( N - 1 , N );
        }

        if ( ( K / N ) + 1 > currBlock )
            R = tree[1] * R;
        else
        {
            R = getMatrix(1 , 1 , N , 1 , K % N ) * R;
            //print( getMatrix(1 , 1 , N , 1 , K % N ) );
            //cout << "Been here " << endl;
        }

        for (int i = 0; i < Changes.size(); i++)
        {
            s[ Changes[i].first % N  ] = Changes[i].second;
            ModifyTree( Changes[i].first % N , N );
        }

        if ( pnt < M && a[pnt].first == currBlock * N )
        {
            s[N] = Last;
            ModifyTree( N - 1 , N );
        }

        prevBlock = currBlock;
    }

    cout << R.a[1][0] % modulo << endl;

    return 0;
}