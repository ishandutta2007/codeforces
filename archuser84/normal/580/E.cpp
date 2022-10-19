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

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 100'010;
char s[N];
int n, m, k;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k; m += k;
	cin >> s;
	while(m--)
	{
		int t, l, r, x;
		cin >> t >> l >> r >> x; --l;
		if(t==1){
			char c = x+'0';
			Loop(i,l,r) s[i]=c;
		} else {
			int cnt = 0;
			Loop(i,l,r-x) cnt += s[i]==s[i+x];
			cout << (cnt==r-l-x?"YES\n":"NO\n");
		}
	}
}