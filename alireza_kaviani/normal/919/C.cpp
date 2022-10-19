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

int cnt(string s , int k)
{
    if(s.size() < k)    return 0;
    int ans = 0;
    vector<int> ok(s.size() , 0);
    for(int i = 0 ; i <= s.size() - k ; i++)
    {
        if(i == 0 || ok[i - 1] != 1)
        {
            ok[i] = 1;
            for(int j = i ; j < i + k ; j++)
            {
                if(s[j] == '*')
                {
                    ok[i] = 0;
                }
            }
        }
        else if(s[i + k - 1] == '.')    ok[i] = 1;
        ans += ok[i];
    }
    return ans;
}

int main()
{
    fast_io;

    ll n , m , k , ans = 0;
    cin >> n >> m >> k;

    string s[n] , t[m];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(int j = 0 ; j < m ; j++)    t[j] += s[i][j];
    }

    for(int i = 0 ; i < n ; i++)    ans += cnt(s[i] , k);
    for(int i = 0 ; i < m ; i++)    ans += cnt(t[i] , k);
    cout << (k == 1 ? ans / 2 : ans);

    return 0;
}