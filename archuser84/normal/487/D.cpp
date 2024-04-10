///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

const int N = 100032;
const int lgM = 4;
const int M = 1<<lgM;
const int S = 3*256;
char b[N*M];
int a[N*M];
bool pre[N*M];
int nxt[N*M];
int n, m, q;

int hlp[N*M], hlps;

int get(int v)
{
	if (!a[v])
		return v;
	if (pre[v])
		return get(nxt[v]);
	hlps = 0;
	int hld = v|(M-1);
	while (a[v] && hld-v < (S-1)*M) {
		hlp[hlps++] = v;
		v += a[v];
		hlp[hlps++] = v;
		v += a[v];
	}
	Loop (i,0,hlps) {
		pre[hlp[i]] = 1;
		nxt[hlp[i]] = v;
	}
	return get(v);
}


int conv(char c)
{
	switch (c) {
	case '<': return -1;
	case '>': return +1;
	case '^': return -M;
	}
	return 0;
}

void up(int i)
{
	a[i] = conv(b[i]);
	if (b[i] == '>' && b[i+1] == '<')
		a[i] = 0;
	if (b[i-1] == '>' && b[i] == '<')
		a[i] = 0;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> q;
	Loop (i,1,n+1) Loop (j,1,m+1)
		cin >> b[i*M + j];
		//b[i*M + j] = '^';
	Loop (i,M,(n+1)*M)
		up(i);
	while (q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		//c = 'A'; x = n; y = q%m+1;
		int i = x*M + y;
		if (c == 'A') {
			int ans = get(i);
			if (ans < M)
				cout << "0 " << ans << '\n';
			else if (ans%M == 0)
				cout << ans/M << " 0" << '\n';
			else if (ans%M == m+1)
				cout << ans/M << " " << m+1 << '\n';
			else
				cout << "-1 -1" << '\n';
		} else /* if (c == 'C') */ {
			cin >> b[i];
			up(i-1);
			up(i);
			up(i+1);
			memset(pre+(i-i%M), 0, min(S*M, (int)sizeof(pre)-(i-i%M)));
		}
	}
}