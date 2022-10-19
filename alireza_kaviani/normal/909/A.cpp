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
inline int input(){int n; cin >> n ; return n;}

string f(string s , char t)
{
    string ans = s.substr(0 , 1);
    for(int i = 1 ; i < s.size() ; i++)
    {
        if(s[i] >= t)
        {
            return ans;
        }
        ans += s[i];
    }
    return ans;
}

int main()
{
    fast_io;

    string fn , ln;
    cin >> fn >> ln;
    cout << f(fn , ln[0]) << ln[0] << endl;

    return 0;
}