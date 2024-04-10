#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 500;
ll n , a[MAXN][MAXN] , row[MAXN] , col[MAXN] , d[] = {0 , 0} , r = 0 , c = 0 , t = 0 , t2 = 0;

int check(ll x)
{
    a[r][c] = x;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum += a[0][i];
    }

    ll s1 = 0 , s2 = 0;
    for(int i = 0 ;i < n ; i++)
    {
        s1 += a[i][i];
        s2 += a[i][n - i - 1];

        ll s3 = 0 , s4 = 0;
        for(int j = 0 ;j < n;  j++)
        {
            s3 += a[i][j];
            s4 += a[j][i];
        }
        if(s3 != sum || s4 != sum)
        {
            return -1;
        }
    }
    if(s1 != sum || s2 != sum)
    {
        return -1;
    }
    return 0;
}

int main()
{
    fast_io;

    cin >> n;

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0LL)
            {
                r = i;
                c = j;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        d[0] += a[i][i];
        d[1] += a[i][n - i - 1];

        if(i == r && i == c)
        {
            t = 1;
        }
        if(i == r && (n - i - 1) == c)
        {
            t2 = 1;
        }

        for(int j = 0 ;j < n; j++)
        {
            row[i] += a[i][j];
            col[i] += a[j][i];
        }
    }

    ll x = row[abs(r - 1)] - row[r];
    cout << (check(x) == -1 || x <= 0LL ? -1 : x);

    return 0;
}