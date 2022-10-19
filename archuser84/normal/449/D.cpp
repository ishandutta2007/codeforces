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

const int lg = 20;
const int N = 1<<lg;
int a[N];

void sos(){
	for(int k = 1; k < N; k <<= 1)
		Loop(i,0,N)
			if(i&k)
				a[i^k] += a[i];
}

const int mod = 1e9+7;
ll mpow(ll x, ll y){ll ans=1;while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		a[x]++;
	}
	sos();
	//Loop(i,0,16) cout << a[i] << ' ';
	//cout << '\n';
	ll ans = 0;
	Loop(i,0,N)
		ans += __builtin_popcount(i)&1? -mpow(2,a[i]): mpow(2,a[i]);
	ans = (ans%mod+mod)%mod;
	cout << ans << '\n';
}