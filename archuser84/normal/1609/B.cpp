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

int n;
string s;

bool ok(int i){
	if(i<2 || i>=n) return 0;
	return s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a';
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int q;
	cin >> n >> q >> s;
	int ans = 0;
	Loop(i,0,n) ans += ok(i);
	while(q--)
	{
		int p; char c;
		cin >> p >> c; --p;
		Loop(i,p,p+3) ans -= ok(i);
		s[p]=c;
		Loop(i,p,p+3) ans += ok(i);
		cout << ans << '\n';
	}
}