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

bool invaild(vector<string> s , int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < s[0].size() ; j++)
        {
            int k = 0;
            while(s[i] != s[0] && k < s[0].size()) s[i] = s[i].substr(1 , s[i].size() - 1) + s[i][0] , k++;
            if(s[i] != s[0])    return 1;
        }
    }
    return 0;
}

int get(vector<string> s , int n)
{
    int ans = 0;
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j < s[0].size() ; j++)
        {
            int k = 0;
            while(s[i] != s[0] && k < n) s[i] = s[i].substr(1 , s[i].size() - 1) + s[i][0] , k++;
            ans += k;
        }
    }
    return ans;
}

int main()
{
    fast_io;

    int n , mn = 2e9;
    cin >> n;

    vector<string> s(n);
    for(int i = 0 ; i < n ; i++)    cin >> s[i];
    if(invaild(s , n))  return cout << -1 << endl , 0;

    for(int i = 0 ; i < s[0].size() ; i++)
    {
        mn = min(mn , get(s , n) + i);
        s[0] = s[0].substr(1 , s[0].size() - 1) + s[0][0];
    }
    cout << mn << endl;

    return 0;
}