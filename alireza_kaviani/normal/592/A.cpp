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

    int A = 100 , B = 100;
    string s[8];
    for(int i = 0 ; i < 8 ; i++)    cin >> s[i];

    for(int i = 0 ; i < 8 ; i++)
    {
        int t = 100;
        for(int j = 0 ; j < 8 ; j++)
        {
            if(s[j][i] == 'W')    { t = j; break;}
            if(s[j][i] != '.')  break;
        }
        A = min(A , t);
        t = 100;
        for(int j = 7 ; j >= 0 ; j--)
        {
            if(s[j][i] == 'B')    { t = 7 - j; break;}
            if(s[j][i] != '.')  break;
        }
        B = min(B , t);
    }
    if(A <= B)  return cout << "A" << endl , 0;
    cout << "B" << endl;

    return 0;
}