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

int f(int x , int y , int n)
{
    if(x % n <= y)
    {
        return x / n;
    }
    return x / n + 1;
}

int main()
{
    fast_io;

    int n , now = 0;
    cin >> n;

    vector<pii> vec;
    for(int i = 0 ; i < n ; i++)
    {
        int x;  cin >> x;
        vec.push_back({f(x , i , n) , i});
    }
    Sort(vec);
    cout << vec[0].Y + 1;

    return 0;
}