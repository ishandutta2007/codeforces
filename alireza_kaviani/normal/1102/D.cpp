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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

ll n , k , cnt[3];
string s;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> s;
    k = n / 3;
    for(ll i = 0 ; i < n ; i++)
    {
        cnt[s[i] - 48]++;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] == '1' && cnt[1] > k && cnt[0] < k)
        {
            s[i] = '0';
            cnt[1]--;
            cnt[0]++;
        }
        else if(s[i] == '2' && cnt[2] > k && cnt[0] < k)
        {
            s[i] = '0';
            cnt[2]--;
            cnt[0]++;
        }
        else if(s[i] == '2' && cnt[2] > k && cnt[1] < k)
        {
            s[i] = '1';
            cnt[2]--;
            cnt[1]++;
        }
    }

    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        if(s[i] == '0' && cnt[0] > k && cnt[2] < k)
        {
            s[i] = '2';
            cnt[0]--;
            cnt[2]++;
        }
        else if(s[i] == '0' && cnt[0] > k && cnt[1] < k)
        {
            s[i] = '1';
            cnt[0]--;
            cnt[1]++;
        }
        else if(s[i] == '1' && cnt[1] > k && cnt[2] < k)
        {
            s[i] = '2';
            cnt[1]--;
            cnt[2]++;
        }
    }
    cout << s << endl;

    return 0;
}