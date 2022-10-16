#include<bits/stdc++.h>
using namespace std;
 
#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
//			  0123456789
const int MOD = 1000000007;
const int MX  = 200002;
const int INF = 2147483647;
 
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
 
unordered_map<int, int> cx, cy;
map<ii, int> xy;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x, y, minX, minY;
	cin>>n;
	cx.reserve(1024);
	cy.reserve(1024);
	cx.max_load_factor(0.25);
	cy.max_load_factor(0.25);
	ll ans = 0;
	f(i, 0, n-1)
	{
		cin>>x>>y;
		cx[x]++;
		cy[y]++;
		xy[mp(x, y)]++;
	}
	for(auto p:cx) ans += 1LL * p.ss * (p.ss-1)/2;
	for(auto p:cy) ans += 1LL * p.ss * (p.ss-1)/2;
	for(auto p:xy) ans -= 1LL * p.ss * (p.ss-1)/2;
	cout << ans << "\n";
	return 0;
}