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

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		float x, y;
		int _x, _y;
		int p1, p2;
		cin >> _x >> p1 >> _y >> p2;
		x = _x; y = _y;
		while(x >= 10) {x/=10;p1++;}
		while(y >= 10) {y/=10;p2++;}
		cout << (p1<p2||(p1==p2&&x<y)?'<':p1==p2&&x==y?'=':'>') << '\n';
	}
}