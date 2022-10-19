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

int change(string s , string t)
{
    int ans = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != t[i])
        {
            ans++;
        }
    }
    return ans;
}

map<string , int> cnt;

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    ///vector<pair<int , string>> a , b;
    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;
        ///a.push_back({s.size() , s});
        cnt[s]++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;
        ///b.push_back({s.size() , s});
        cnt[s]--;
    }
    /**Sort(a);
    Sort(b);*/

    for(auto &i : cnt)
    {
        ans += (i.Y > 0 ? i.Y : 0);
    }
    cout << ans << endl;

    return 0;
}