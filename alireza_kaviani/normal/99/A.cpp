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
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

string s , ans;
ll ind , flag;

int main()
{
    fast_io;

    cin >> s;
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '.' && s[i + 1] < '5')   return cout << (s[i - 1] == '9' ? "GOTO Vasilisa." : s.substr(0 , i)) << endl , 0;
        if(s[i] == '.') ind = i - 1;
    }
    if(s[ind] == '9')   return cout << "GOTO Vasilisa." << endl , 0;
    cout << s.substr(0 , ind) + string(1 , (s[ind] + 1)) << endl;


    return 0;
}