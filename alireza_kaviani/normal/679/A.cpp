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

const int MAXN = 110;
int prime[MAXN];

int main()
{
    fast_io;

    fill(prime , prime + MAXN , 1);
    prime[1] = 0;
    for(int i = 1 ; i * i <= MAXN ; i++)
    {
        if(prime[i])
        {
            for(int j = i * i ; j < MAXN ; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    int cnt = 0;
    for(int i = 2 ; i <= 50 ; i++)
    {
        if(prime[i])
        {
            cout << i << endl;
            string s;
            cin >> s;
            if(s == "yes")  cnt++;
            if(cnt >= 2)    return cout << "composite" << endl , 0;
            if(s == "yes" && i * i <= 100)
            {
                cout << i * i << endl;
                cin >> s;
                if(s == "yes")  return cout << "composite" << endl , 0;
            }
        }
    }
    cout << "prime" << endl ;
    return 0;
}