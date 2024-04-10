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

map<char , ll> cnt;

int main()
{
    fast_io;

    ll n;
    string s;
    char c[4] = {'A' , 'T' , 'C' , 'G'};
    cin >> n >> s;

    if(n % 4) return cout << "===" << endl , 0;

    for(ll i = 0 ; i < n ; i++)
    {
      if(s[i] != '?') cnt[s[i]]++;
      if(cnt[s[i]] > n / 4) return cout << "===" << endl , 0;
    }

    for(ll i = 0 ; i < n ; i++)
    {
      if(s[i] == '?')
      {
        for(ll j = 0 ; j < 4 ; j++)
        {
          if(cnt[c[j]] < n / 4)  { s[i] = c[j]; cnt[c[j]]++; break;}
        }
      }
    }
    cout << s << endl;

    return 0;
}