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
    
    string s , names[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int n;
    cin >> n >> s;
    
    for (int i = 0 ;i < 8 ; i++)
    {
    	if (names[i].size() == n)
    	{
    		int ans = 1;
    		for (int j = 0 ; j < n ; j++)
    		{
    			if (s[j] != '.' && names[i][j] != s[j]) ans = 0;
    		}
    		if (ans)
    		{
    			return cout << names[i] << endl , 0;
    		}
    	}
    }
    
    return 0;
}