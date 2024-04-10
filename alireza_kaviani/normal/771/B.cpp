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

string get(int x)
{
    return string(1 , x / 26 + 65) + string(1 , x % 26 + 97);
}

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    string ans[n];
    for(int i = 0 ; i < k - 1 ; i++)    ans[i] = get(i);

    for(int i = k - 1 ; i < n ; i++)
    {
        string s;
        cin >> s;
        if(s == "NO")   ans[i] = ans[i - k + 1];
        else    ans[i] = get(i);
    }
    for(int i = 0 ; i < n ; i++)    cout << ans[i] << ends;

    return 0;
}