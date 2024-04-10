///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 22;
array<int, N> A[N+1];
pii dp[1<<N];
int n, m;

void calc(int i, int msk)
{
	if(i==n){
		bool gd = 1;
		Loop(j,0,n) if(A[n][j] != (1<<n)-1) gd = 0;
		if(gd) return;
		dp[msk] = {N+1, -1};
		Loop(j,0,n){
			if(msk&(1<<j)) continue;
			dp[msk] = min(dp[msk], {dp[msk^(1<<j)].first+1, j});
		}
		return;
	}
	A[i+1] = A[i];
	Loop(j,0,n) if(A[i][i]&(1<<j)) A[i+1][j] |= A[i][i];
	calc(i+1, msk^(1<<i));
	A[i+1] = A[i];
	calc(i+1, msk);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[0][v] |= (1<<u);
		A[0][u] |= (1<<v);
	}
	Loop(i,0,n) A[0][i] |= (1<<i);
	calc(0,0);
	cout << dp[0].first << '\n';
	for(int msk = 0; dp[0].first--;){
		cout << dp[msk].second+1 << ' ';
		msk ^= 1<<dp[msk].second;
	}
	cout << '\n';
}