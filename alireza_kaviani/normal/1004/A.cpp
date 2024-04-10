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

    int n , d , ans = 2;
    cin >> n >> d;

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    sort(a , a + n);

    set<int> st;
    for(int i = 0 ; i < n ; i++)
    {
        int x = a[i] - d , y = a[i] + d;
        if(i != 0 && abs(a[i] - a[i - 1]) >= d * 2)
        {
            st.insert(x);
        }
        if(i != n - 1 && abs(a[i] - a[i + 1]) >= d * 2)
        {
            st.insert(y);
        }
    }
    cout << st.size() + 2 << endl;

    return 0;
}