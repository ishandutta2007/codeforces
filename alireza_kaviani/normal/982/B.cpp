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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 + 10;
ll n , ind = 0;
pll w[MAXN];
string s;
stack<ll> stk;

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++) w[i] = {input() , i + 1};
    cin >> s;
    sort(w , w + n);

    for(ll i = 0 ; i < n * 2 ; i++)
    {
        if(s[i] == '1')
        {
            cout << stk.top() << ends;
            stk.pop();
        }
        else
        {
            cout << w[ind].Y << ends;
            stk.push(w[ind++].Y);
        }
    }

    return 0;
}