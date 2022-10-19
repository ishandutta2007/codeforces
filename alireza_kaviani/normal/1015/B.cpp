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

int find(string s , char c)
{
    for(int i = s.size() - 1 ; i >= 0 ; i--)
    {
        if(s[i] == c)   return i;
    }
    return -1;
}

int main()
{
    fast_io;

    int n;
    string s , t;
    cin >> n >> s >> t;

    swap(s , t);
    vector<int> ans;
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int x = find(t.substr(0 , i + 1) , s[i]);
        if(x == -1) return cout << -1 << endl , 0;
        for(int j = x ; j < i ; j++)
        {
            ans.push_back(j);
            swap(t[j] , t[j + 1]);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++)   cout << ans[i] + 1 << ends;

    return 0;
}