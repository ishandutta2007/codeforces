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

int main()
{
    fast_io;

    int n , k , ans = 0;
    string s;
    cin >> n >> k >> s;

    vector<int> a = {-1} , b = {-1};
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == 'a') a.push_back(i);
        if(s[i] == 'b') b.push_back(i);
    }
    a.push_back(n);
    b.push_back(n);

    for(int i = 0 ; i < a.size() ; i++)
    {
        int x = a[min((int)a.size() - 1 , i + k + 1)] - a[i] - 1;
        ans = max(ans , x);
    }
    for(int i = 0 ; i < b.size() ; i++)
    {
        int x = b[min((int)b.size() - 1 , i + k + 1)] - b[i] - 1;
        ans = max(ans , x);
    }
    cout << ans << endl;

    return 0;
}