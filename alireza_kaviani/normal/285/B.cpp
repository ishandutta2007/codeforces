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

int main()
{
    fast_io;

    int n , s , t , ans = 0;
    cin >> n >> s >> t;
    s--; t--;

    bool see[n];
    int p[n];
    for(int i = 0 ; i < n ; i++)    { cin >> p[i]; p[i]--;}

    fill(see , see + n , 0);
    while(s != t)
    {
        if(see[s])
        {
            cout << -1 << endl;
            return 0;
        }
        see[s] = 1;
        s = p[s];
        ans++;
    }
    cout << ans << endl;

    return 0;
}