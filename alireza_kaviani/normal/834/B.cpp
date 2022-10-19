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

map<char , int> l , r;

int main()
{
    fast_io;

    int n , k , cnt = 0;
    string s;
    cin >> n >> k >> s;

    int d[n + 1];
    for(int i = 0 ; i < n ; i++)
    {
        (r[s[i]] == 0 ? l[s[i]] = i : l[s[i]] = l[s[i]]);
        r[s[i]] = i + 1;
    }

    fill(d , d + n + 1 , 0);
    for(auto &i : l)    d[i.Y]++;
    for(auto &i : r)    d[i.Y]--;

    for(int i = 0 ; i < n ; i++)
    {
        cnt += d[i];
        if(cnt > k) return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;
    return 0;
}