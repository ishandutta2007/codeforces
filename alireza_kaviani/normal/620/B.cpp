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

int segs[] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
int get(int n)
{
    int ans = 0;
    while(n != 0)
    {
        ans += segs[n % 10];
        n /= 10;
    }
    return ans;
}

int main()
{
    fast_io;

    int a , b , ans = 0;
    cin >> a >> b;
    for(int i = a ; i <= b ; i++)   ans += get(i);
    cout << ans << endl;

    return 0;
}