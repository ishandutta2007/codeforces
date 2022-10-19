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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }


int main()
{
    fast_io;

    int n , mini = 2e9;
    cin >> n;

    vector<int> a(n) , b(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(a));
    sort(all(b));

    for(int i = 0 ; i < n ; i++)
    {
        int id = upper_bound(all(b) , a[i]) - b.begin();
        if(id == b.size()) return cout << i << endl , 0;
        b.erase(b.begin() + id);
    }
    cout << n << endl;

    return 0;
}