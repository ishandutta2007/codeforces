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

int main()
{
    fast_io;

    map<char , int> mp;
    int n , ans = 0;
    string s;
    cin >> n >> s;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        char k = s[i * 2] , d = s[i * 2 + 1] + 32;
        mp[k]++;
        if(mp[d] == 0)
        {
            ans++;
        }
        else
        {
            mp[d]--;
        }
    }
    cout << ans << endl;

    return 0;
}