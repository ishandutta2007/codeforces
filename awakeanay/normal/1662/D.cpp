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
#define endl "\n"
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
string reduce(string s) {
  int n = s.size();
  char st[n];
  int top = 0;
 
  for(int i = 0; i < n; i++) {
    st[top++] = s[i];
    if(top >= 2 && st[top-2] == 'A' && st[top-1] == 'A')
      top -= 2;
    else if(top >= 2 && st[top-2] == 'C' && st[top-1] == 'C')
      top -= 2;
  }
 
  string ret(top, 'a');
  for(int i = 0; i < top; i++)
    ret[i] = st[i];
  return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string u, v;
		cin >> u >> v;
		reverse(u.begin(), u.end());
		u += v;
		int cnt = 0;
		string s = "";
		for(auto e : u)
		{
			if(e == 'B')
				cnt++;
			else
				s += e;
		}
		if(cnt % 2)
			cout << "NO" << endl;
		else
		{
			if(reduce(s).size() == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
    return 0;
}