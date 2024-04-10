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

map<char , int> cnt;

int main()
{
    fast_io;

    string s;
    cin >> s;

    for(int i = 0 ;i < s.size() ; i++)
    {
        cnt[s[i]]++;
    }
    int ans = abs(cnt['R'] - cnt['L']) + abs(cnt['U'] - cnt['D']);

    if(ans & 1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans / 2 << endl;
    return 0;
}