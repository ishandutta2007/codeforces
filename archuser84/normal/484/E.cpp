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
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 100'010;
const int lg = 18;
int h[lg][N];
int n, q;

#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> h[0][i];
	Loop(k,0,lg-1) for(int i = 0; i+(2<<k) <= n; ++i)
		h[k+1][i] = min(h[k][i],h[k][i+(1<<k)]);
	cin >> q;
	while(q--)
	{
		int l, r, w;
		cin >> l >> r >> w; --l;
		int k = __lg(w), os = w-(1<<k);
		int ans = 0;
		for(int i = l; i+w <= r; ++i){
			int x = min(h[k][i], h[k][i+os]);
			ans = max(ans, x);
		}
		cout << ans << '\n';
	}
}