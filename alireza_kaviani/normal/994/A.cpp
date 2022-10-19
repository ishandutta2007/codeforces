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

bool in(vector<int> x , int key)
{
    for(int i = 0; i< x.size() ; i++)
    {
        if(x[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    vector<int> x(n) , y(m);
    for(int i = 0 ; i < n;  i++)    cin >> x[i];
    for(int i = 0; i < m ; i++)     cin >> y[i];

    for(int i = 0 ;i < n ; i++)
    {
        if(in(y , x[i]))
        {
            cout << x[i] << ends;
        }
    }

    return 0;
}