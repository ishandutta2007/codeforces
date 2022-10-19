///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    Padoru Padoru   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

const int N = 5010;
const int mod = 1e9+7;
int sum[N];
int cnt[26][N], padoru[N];
ll fct[N], inv[N];

string s;
int n;

ll C(ll n, ll r){return fct[n]*inv[r]%mod*inv[n-r]%mod;}

#define add(x,y){x=x+(y)>=mod?x+(y)-mod:x+(y);}


int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> s;
	sum[0] = 1; Loop(i,0,26) cnt[i][0] = 1;
	Loop(i,0,n)
	{
		int c = s[i]-'a';
		LoopR(j,0,i+1) {
			add(cnt[c][j], padoru[j])
			add(sum[j+1], cnt[c][j]);
			add(padoru[j+1], cnt[c][j]);
			cnt[c][j+1] = padoru[j+1]? mod-padoru[j+1]: 0;
		}
		cnt[c][0] = 0;
	}

	fct[0] = 1; Loop(i,1,N) fct[i] = fct[i-1]*i % mod;
	inv[N-1] = 666751442; LoopR(i,0,N-1) inv[i] = inv[i+1]*(i+1) % mod;

	ll ans = 0;
	Loop(i,1,n+1)
		ans += C(n-1,i-1)*sum[i] % mod;
	cout << ans%mod << '\n';
}