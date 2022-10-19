///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;

int p[N];
int st[N], ft[N], ft2[N];
vector<int> A[N];
int cnt[N];
int n;

int dfs(int v, int& t)
{
	st[v] = t++;
	int cnt = 2;
	for(int u : A[v])
		cnt += dfs(u,t);
	ft2[st[v]] = ft[v] = t;
	return ::cnt[st[v]] = cnt;
}

__attribute((optimize("O3,unroll-loops"), target("avx2")))
int nearest(int y, int l, int r, int v){
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>0?(x):-(x))
	int stv = st[v], cntv = cnt[st[v]];
	int x = y;
	Loop(i,l,r) {
		int z = i<=stv && stv<ft2[i]? cntv: 0;
		z = cnt[i] - z;
		z = abs(z-y);
		x = min(x, z);
	}
	return x;
}

int solve(int v)
{
	if(A[v].size() == 0) return n-1;
	int cntv = cnt[st[v]];
	cnt[0] -= cntv;
	pii mx={0,0}, mx2={0,0}, mn={2*N,0};
	#define find(x, cnd, cmp) {                      \
		for(int u : A[v]) if(cnd)                    \
			{pii y={cnt[st[u]], u}; x = cmp(x, y);}  \
		int u = A[0][0];                             \
		if(cnt[0] && (cnd))                          \
			{pii y={cnt[st[u]], u}; x = cmp(x, y);}  \
	}
	find(mx , true, max);
	find(mx2, u != mx.second, max);
	find(mn , true, min);
	//#undef find
	cnt[0] += cntv;
	int mid = (mx.first - mn.first)/2;
	int x = 4*N;
	if(mx.second == A[0][0]) {
		x = min(x, nearest(mid, 0, st[v], v));
		x = min(x, nearest(mid, ft[v], n, v));
	} else {
		x = min(x, nearest(mid, st[mx.second], ft[mx.second], v));
	}
	x = max(mid+mn.first+x, mx2.first)/2;
	return x;
}

int main()
{
	//Kill("done!");
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n)
	{
		int v, u;
		cin >> v >> u;
		A[v].push_back(u);
	}
	dfs(A[0][0], *new int(0));
	Loop(i,0,n)
		cout << solve(i+1) << '\n';
}