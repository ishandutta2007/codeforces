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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

ll n , k , d = -1 , cnt;
string s , x = "LEFT" , y = "RIGHT";

int main()
{
    fast_io;

    cin >> n >> k >> s;
    if(n - k < k - 1)   {swap(x , y) , d *= -1;}
    for(k-- ; k < n - 1 && k > 0 ; k += d)    cout << x << endl;
    for(; k < n && k >= 0 ; k -= d)
    {
        cout << "PRINT" << sep << s[k] << endl;
        cnt++;
        if(cnt != n)    cout << y << endl;
    }

    return 0;
}