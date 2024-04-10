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

int cnt[3];

int main()
{
    fast_io;
    int p = 97 ;
    string s;
    cin >> s;

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] > p || (s[i] < p && s[i] != p - 1))
        {
            cout << "NO" << endl;
            return 0;
        }
        else if(s[i] == p)
        {
            p++;
        }
        cnt[s[i] - 97]++;
    }
    cout << (p == 100 && (cnt[0] == cnt[2] || cnt[1] == cnt[2]) ? "YES" : "NO") << endl;
    return 0;
}