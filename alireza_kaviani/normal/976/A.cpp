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

int main()
{
    fast_io;

    string s;
    int n = 0 , o = 0;
    cin >> s >> s;

    for(int i = 0; i < s.size() ; i++)
    {
        if(s[i] == '0')
        {
            n ++;
        }
        else
        {
            o++;
        }
    }

    if(o != 0)
    {
        cout << '1';
    }
    for(int i = 0 ;i < n ; i++)
    {
        cout << '0';
    }

    return 0;
}