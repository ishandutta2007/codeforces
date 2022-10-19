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

map<char , bool> mark;

int main()
{
    fast_io;

    int k;
    string s;
    cin >> k >> s;

    vector<int> ans;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(!mark[s[i]])
        {
            mark[s[i]] = 1;
            if(ans.size() < k)  ans.push_back(i);
        }
    }
    ans.push_back(s.size());
    if(ans.size() - 1 < k)  return cout << "NO" << endl , 0;
    cout << "YES" << endl;

    for(int i = 0 ; i < k ; i++)
    {
        cout << s.substr(ans[i] , ans[i + 1] - ans[i]) << endl;
    }

    return 0;
}