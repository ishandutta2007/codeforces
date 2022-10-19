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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

map<char , int> ok;

int main()
{
    fast_io;

    ok['a'] = ok['e'] = ok['i'] = ok['o'] = ok['u'] = 1;

    int ans = 1;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(!ok[s[i]] && !ok[s[i + 1]] && s[i] != 'n') ans = 0;
    }
    cout << (ans == 1 ? "YES" : "NO") << endl;

    return 0;
}