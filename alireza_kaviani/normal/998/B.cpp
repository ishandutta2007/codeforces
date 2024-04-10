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

    int n , b , ev = 0 , od = 0 , sum = 0 , ans = 0;
    cin >> n >> b;

    int a[n];
    vector<int> cut;
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    for(int i = 0 ; i < n - 1; i++)
    {
        if(a[i] % 2 == 0)   ev++;
        else                od++;

        if(od == ev)    cut.push_back(abs(a[i] - a[i + 1]));
    }
    Sort(cut);

    for(int i = 0 ; i < cut.size() ; i++)
    {
        if(sum + cut[i] > b)
        {
            break;
        }
        sum += cut[i];
        ans++;
    }
    cout << ans << endl;

    return 0;
}