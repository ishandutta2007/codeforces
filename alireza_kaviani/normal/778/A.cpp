#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

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

const int MAXN = 2e5 + 10;
int n , m , a[MAXN] , mark[MAXN];
string s , t;

bool check(int ind)
{
    fill(mark , mark + MAXN , 0);
    for(int i = 0 ; i <= ind ; i++) mark[a[i] - 1] = 1;

    int ti = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!mark[i])
        {
            if(ti != m && s[i] == t[ti])    ti++;
        }
    }
    return (ti == m);
}

int binary_search(int l , int r)
{
    if(l == r)  return l;
    int mid = (l + r) / 2;
    if(check(mid))  return binary_search(mid + 1 , r);
    return binary_search(l , mid);
}

int main()
{
    fast_io;

    cin >> s >> t;
    n = s.size();
    m = t.size();

    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    cout << binary_search(0 , n - 1);

    return 0;
}