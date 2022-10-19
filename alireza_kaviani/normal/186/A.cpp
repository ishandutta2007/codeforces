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

    string s , t;
    cin >> s >> t;

    if(s.size() != t.size())    return cout << "NO" << endl , 0;
    vector<int> vec;
    for(int i = 0 ; i < s.size() ; i++)
        if(s[i] != t[i])
            vec.push_back(i);

    if(vec.size() > 2 || vec.size() == 1)   return cout << "NO" << endl , 0;
    if(!(vec.size() == 2 && s[vec[0]] == t[vec[1]] && s[vec[1]] == t[vec[0]]))  return cout << "NO" << endl , 0;
    cout << "YES" << endl;

    return 0;
}