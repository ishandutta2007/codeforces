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

map<int , bool> mark;

int main()
{
    fast_io;

    int n , cnt = 0;
    cin >> n;

    string s[n];
    for(int i = 0 ;i < n ; i++)
    {
        int r;
        cin >> s[i] >> r;
        if(s[i] == "-" && !mark[r])
        {
            cnt++;
        }
        mark[r] = true;
    }

    int ans = cnt;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == "-")
        {
            cnt--;
        }
        else
        {
            cnt++;
        }
        ans = max(ans , cnt);
    }
    cout << ans << endl;

    return 0;
}