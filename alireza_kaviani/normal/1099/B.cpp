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

ll n , ans = 0;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    long long a1,a2,b1,b2,c1,c2;ans++;
    cin >> a1;ans++;
    b1 = sqrt(a1)/1+1;ans++;
    if (a1%b1 == 0){
    	c2 = a1/b1+b1;ans++;
	}
	else {
		c2 = a1/b1+1+b1;ans++;
	}
    for(int i = long(sqrt(a1)); i > 0; --i){
    	if (a1%i == 0){
    		c1 = i+(a1/i);ans++;
    		break;
		}
	}
	if (c1 < c2){
		cout << c1;
		return 0;
	}
	cout << c2;
	return 0;
}