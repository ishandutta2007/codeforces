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
const int N = 2e5 + 5;
int s;
vvi graph(N);
vi visited(N), par(N);
int node = -1, branch;
void dfs(int x, int idx)
{
	if(visited[x] && visited[x] != idx)
	{
		node = x;
		branch = visited[x];
		return;
	}
	visited[x] = idx;
	for(auto e : graph[x])
	{
		if(e == s)
			continue;
		if(!visited[e])
		{
			par[e] = x;
			dfs(e, idx);
		}
		else if(visited[e] != idx)
		{
			par[e] = x;
			node = e;
			branch = visited[e];
			return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m >> s;
	fort(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
	}
	int idx = 1, branch2;
	for(auto e : graph[s])
	{
		par[e] = s;
		dfs(e, idx);
		if(node != -1)
		{
			branch2 = idx;
			break;
		}
		idx++;
	}
	if(node == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	// debug(node, branch, branch2);
	vi path;
	int x = node;
	while(x != s)
	{
		path.pb(x);
		x = par[x];
	}
	path.pb(s);
	reverse(path.begin(), path.end());
	int branch_head = graph[s][branch - 1];
	// debug(branch_head);
	visited.assign(n + 1, 0);
	dfs(branch_head, branch);
	// fort(i, 1, n + 1)
	// 	debug(i, par[i]);
	vi path2;
	par[branch_head] = s;
	x = node;
	while(x != s)
	{
		path2.pb(x);
		x = par[x];
	}
	path2.pb(s);
	reverse(path2.begin(), path2.end());
	int s1 = path.size(), s2 = path2.size();
	while(s1 > 0 && s2 > 0)
	{
		if(path[s1 - 1] == path2[s2 - 1])
		{
			s1--, s2--;
		}
		else
			break;
	}
	s1++, s2++;
	cout << s1 << endl;
	fort(i, 0, s1)
		cout << path[i] << " ";
	cout << endl;
	cout << s2 << endl;
	fort(i, 0, s2)
		cout << path2[i] << " ";
	cout << endl;
    return 0;
}