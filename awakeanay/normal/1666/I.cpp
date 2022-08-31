#include<bits/stdc++.h>		
// #define int long long
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pr;
typedef vector<pair<int,int> > vpr;
typedef vector<vi> vvi;
#define ff first
#define ss second
#define fort(i,m,n) for(int i=m;i<n;i++)
#define fora(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define begud(k) cerr<<"\t-->"<<#k<<" = "<<k<<"\n";
#define debug(args...) { string _debug_list = #args; replace(_debug_list.begin(), _debug_list.end(), ',', ' '); stringstream _debug_stream(_debug_list); istream_iterator<string> __it(_debug_stream); debug_func(__it, args); }
// #define endl "\n"
#define pb push_back
/* 
// What follows is a magical ordered set data structure.
// Supports the following functions:
// find_by_order(int k) - returns k'th smallest element (0-indexed)
// order_of_key(int k) - returns number of elements strictly smaller than k.
using namespace __gnu_pbds;
#define ordered_set tree <ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
 */
const int mod = 1e9 + 7, mod2 = 998244353;
void debug_func(istream_iterator<string> _it) {
	cerr << "\n";
} 
template <typename T, typename... Args>
void debug_func(istream_iterator<string> _it, T x, Args... args) {
	cerr << "[ " << *_it << " : " << x << " ]";
	cerr << " , ";
	debug_func(++_it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long true_rand(long long n) {
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
	uniform_int_distribution<long long> uid(0, n - 1);
	return uid(rng);
}
ll power(ll a,ll b)
{
	a = a % mod;
	if(a == 0)
		return 0;
	ll ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
	return ans;
}
template<typename T>
bool sortbysec(const pair<T,T> &a,const pair<T,T> &b)                
{
	return (a.second < b.second); 
}
int scan(int r, int c)
{
	cout << "SCAN " << r << " " << c << endl;
	int x;
	cin >> x;
	return x;
}
int dig(int r, int c)
{
	cout << "DIG " << r << " " << c << endl;
	int x;
	cin >> x;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int a = scan(1, 1);
		int b = scan(1, m);
		int xsum = (a + b - 2 * m + 6) / 2;
		int ysum = (a - b + 2 + 2 * m) / 2;
		int xmid = xsum / 2;
		int c = scan(xmid, 1);
		int xdiff = c - ysum + 2;
		int ymid = ysum / 2;
		int d = scan(1, ymid);
		int ydiff = d - xsum + 2;
		int x1 = (xsum + xdiff) / 2;
		int x2 = (xsum - xdiff) / 2;
		int y1 = (ysum + ydiff) / 2;
		int y2 = (ysum - ydiff) / 2;
		if(dig(x1, y1))
			dig(x2, y2);
		else
		{
			dig(x1, y2);
			dig(x2, y1);
		}
	}
    return 0;
}