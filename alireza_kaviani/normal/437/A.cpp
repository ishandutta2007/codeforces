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

    string s[4];
    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> s[i];
        s[i] = s[i].substr(2 , s[i].size() - 2);
    }

    vector<int> goods;
    for(int i = 0 ; i < 4 ; i++)
    {
        int cs = 0 , cl = 0;
        for(int j = 0 ; j < 4 ; j++)
        {
            if(s[i].size() * 2 <= s[j].size())  cs++;
            if(s[j].size() * 2 <= s[i].size())  cl++;
        }
        if(cl == 3 || cs == 3)  goods.push_back(i);
    }
    if(goods.size() != 1)    return cout << "C" << endl , 0;
    cout << char(goods[0] + 'A') << endl;

    return 0;
}