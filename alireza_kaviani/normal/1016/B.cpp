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

const int MAXN = 2e3 + 10;
int cnt[MAXN];

int main()
{
    fast_io;

    int n , m , q;
    string s , key;
    cin >> n >> m >> q >> s >> key;

    for(int i = 0 ; i <= n - m ; i++)
    {
        int add = 0;
        if(s.substr(i , m) == key)
        {
            add = 1;
        }
        cnt[i + m - 1] = cnt[i  + m - 2] + add;
    }
    for(int i = n ; i < MAXN ; i++) cnt[i] = cnt[i - 1];

    while(q--)
    {
        int l , r;
        cin >> l >> r;
        l--; r--;
        cout << (l == 0 ? cnt[r] : max(0 , cnt[r] - cnt[l + m - 2])) << endl;
    }

    return 0;
}