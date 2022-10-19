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

    int n , p = 0 , l = 0 , wp = 0;
    string s , k = "";
    cin >> n >> s;

    s += "_";
    for(int i = 0 ; i <= n ; i++)
    {
        if(s[i] == '_' || s[i] == '(' || s[i] == ')')
        {
            if(k != "")
            {
                if(p == 1)
                {
                    wp++;
                }
                else
                {
                    l = max((int)k.size() , l);
                }
                k = "";
            }

            if(s[i] == '(')
            {
                p = 1;
            }
            if(s[i] == ')')
            {
                p = 0;
            }
        }
        else
        {
            k += s[i];
        }
    }

    cout << l << ends << wp << endl;

    return 0;
}