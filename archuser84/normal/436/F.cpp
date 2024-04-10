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
#define max(x,y) ((x)>(y)?(x):(y))

const int N = 100'032;
ll ps[N];
vector<int> vec[N];
ll n, w;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	Loop(i,0,N) ps[i] = i;
	cin >> n >> w;
	ll mx=0;
	Loop(i,0,n){
		int a, b;
		cin >> a >> b;
		vec[b].push_back(a);
		mx = max(mx, b);
	}
	cout << "0 0\n";
    ll Ans=N-1;
	Loop(i,0,mx+1){
		for(int x : vec[i]){
			Loop(j,0,x+1){
				ps[j] += j<<17;
                Ans = max(Ans, ps[j]);
            }
			--n;
		}
		ll ansi = Ans;
		ll ans = ansi>>17;
		ansi -= ans<<17;
		cout << ans + n*(i+1)*w << ' ' << ansi << '\n';
	}
}