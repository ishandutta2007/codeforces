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

int sub(int h , int m , int h2, int m2)
{
    int t = h * 60 + m , t2 = h2 * 60 + m2;
    if(t > t2)
    {
        t2 += 24 * 60;
    }
    return t2 - t;
}

double ans[24][60];

int main()
{
    int h , m , hu , d, c , n;
    cin >> h >> m >> hu >> d >> c >> n;

    double minn = 1e9;
    for(int i = 0 ; i < 24 ; i++)
    {
        for(int j = 0; j < 60 ; j++)
        {
            int t = sub(h , m , i , j);

            ans[i][j] = ceil(double((t * d + hu)) / double(n))  * c;
            if(i >= 20)
            {
                ans[i][j] = ans[i][j] * 80.0 / 100.0;
            }
            minn = min(minn , ans[i][j]);
        }
    }
    printf("%.10f" , minn);

    return 0;
}