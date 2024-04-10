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

bool reversed(string s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fast_io;

    int ans = 0;
    string s;
    cin >> s;

    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = i ;j < s.size() ; j++)
        {
            string t = "";
            for(int k = i ; k <= j ; k++)
            {
                t += s[k];
            }
            if(reversed(t) == false)
            {
                ans = max(ans , (int)t.size());
            }
        }
    }
    cout << ans << endl;

    return 0;
}