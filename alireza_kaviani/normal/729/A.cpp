#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , t = 1;
    string s;
    cin >> n >> s;

    while(t)
    {
        t = 0;
        for(int i = 0 ; i + 2 < s.size() ; i++)
        {
            if(s.substr(i , 3) == "ogo")
            {
                s[i] = s[i + 1] = s[i + 2] = '*';
                while(i + 4 < s.size() && s[i + 3] == 'g' && s[i + 4] == 'o')
                {
                    s.erase(s.begin() + i + 3);
                    s.erase(s.begin() + i + 3);
                }
                t = 1;
                break;
            }
        }
    }
    cout << s << endl;

    return 0;
}