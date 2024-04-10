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
		ll a, b, x;
		cin >> a >> b >> x;
		while(1){
			if(a > b) swap(a, b);
			if(a == 0) {cout << "NO\n"; break;}
			if(x > b) {cout << "NO\n"; break;}
			if((b-x)%a==0) {cout << "YES\n"; break;}
			b %= a;
		}
	}
}