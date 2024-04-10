///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1e6+10;
int a[N], b[N], p[N];
int ans=0;
int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(b, -1, sizeof b);
	cin >> n;
	Loop(i,1,n+1)
	{
		cin >> p[i]; --p[i];
		int v = p[i], lst=0;
		while(v){
			int x = a[v];
			a[v] = max(a[v], lst==b[v]?lst+1:lst);
			b[v] = max(b[v], lst);
			lst = a[v];
			ans = max(ans, a[v]);
			if(x == a[v]) break;
			v = p[v];
		}
		cout << ans+1 << ' ';
	}
	cout << '\n';
}