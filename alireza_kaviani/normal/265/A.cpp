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

    string s , t;
    int pos = 0;
    cin >> s >> t;

    for(int i = 0 ;i < t.size() ; i++)
    {
        if(s[pos] == t[i])
        {
            pos++;
        }
        if(pos == s.size())
        {
            cout << pos << endl;
            return 0;
        }
    }

    cout << pos + 1 << endl;

    return 0;
}