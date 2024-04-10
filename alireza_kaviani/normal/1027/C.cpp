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
inline int input(){int n; scanf("%d" , &n) ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXSZ = 1e6 + 10 , MAXN = 1e4 + 10;
int cnt[MAXN] , vec[MAXSZ];

double f(double x , double y)
{
    return ((2.0 * (x + y)) * (2.0 * (x + y))) / (x * y);
}

int main()
{
    fast_io;

    int q;
    cin >> q;

    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)    { cin >> a[i] ; cnt[a[i]] = 0;}
        for(int i = 0 ; i < n ; i++)    cnt[a[i]]++;

        int t = 0 , can = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(cnt[a[i]] >= 4) { cout << a[i] << ends << a[i] << ends << a[i] << ends << a[i] << endl; can = 1; break;}
            if(cnt[a[i]] >= 2) vec[t++] = a[i];
            cnt[a[i]] = 0;
        }
        if(can) continue;

        sort(vec , vec + t);
        int x = 0 , y = 0 , see = -1;
        for(int i = 0 ; i < t - 1 ; i++)
        {
            if(see == -1 || f(x , y) > f(vec[i] , vec[i + 1]))
            {
                see = 1;
                x = vec[i];
                y = vec[i + 1];
            }
        }
        cout << x << ends << x << ends << y << ends << y << endl;
    }

    return 0;
}