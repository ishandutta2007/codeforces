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

    string s , s2;
    cin >> s >> s2;

    int l = s[0] - s2[0] , d = s[1] - s2[1] , t = max(abs(l) , abs(d));
    cout << t << endl;
    for (int i = 0; i < t ; i++)
    {
        if(l > 0)
        {
            cout << 'L';
            l--;
        }
        else if(l != 0)
        {
            cout << 'R';
            l++;
        }

        if(d > 0)
        {
            cout << 'D';
            d--;
        }
        else if(d != 0)
        {
            cout << 'U';
            d++;
        }
        cout << endl;
    }

    return 0;
}