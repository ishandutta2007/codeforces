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

#define int ll

const int N = 600100;
int n, k, m;
int l[N], r[N];
vector<int> st[N], ft[N];
vector<int> cmp;

short bs[N];


#define set(i) {if(bs[i] == 0) {cnt += 1; bs[i] = 1;}}
#define reset(i) {if(bs[i] == 1) {cnt -= 1;} bs[i] = 2;}

bool solve(int x)
{
	if (x == 0) {
		fill(bs, bs + N, 1);
		return 1;
	}
	memset(bs, 0, sizeof(bs));
	int cnt = 0;
	int len = 0;
	int p1=0, p2=0;
	while (len < x && p2 < m) {
		len += cmp[p2+1] - cmp[p2];
		for (int j : ft[p2])
			reset(j);
		++p2;
	}
//	cout << "\n\n";
//	cout << p1 << ' ' << p2 << ' ' << len << ' ' << cnt << endl;
	if (len < x)
		return 0;
	while (true) {
		while (len >= x) {
			len -= cmp[p1+1] - cmp[p1];
			for (int j : st[p1])
				set(j);
			++p1;
		}
//		cout << p1 << ' ' << p2 << ' ' << len << ' ' << cnt << endl;
		if (cnt >= k)
			return 1;
		while (len < x && p2 < m) {
			len += cmp[p2+1] - cmp[p2];
			for (int j : ft[p2])
				reset(j);
			++p2;
		}
		if (len < x)
			return 0;
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,0,n) {
		cin >> l[i] >> r[i];
		--l[i];
		cmp.push_back(l[i]);
		cmp.push_back(r[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	m = cmp.size() - 1;
	//cout << m << '\n';
	Loop(i,0,n) {
		int l, r;
		l = lower_bound(cmp.begin(), cmp.end(), ::l[i]) - cmp.begin();
		r = lower_bound(cmp.begin(), cmp.end(), ::r[i]) - cmp.begin();
		st[l].push_back(i);
		ft[r].push_back(i);
	}
	int l=0,r=2e9+100;
	while (l < r) {
		int m = (l+r+1)/2;
		if(solve(m))
			l = m;
		else
			r = m-1;
	}
	solve(l);
	cout << l << '\n';
	for (int i = 0, cnt = 0; cnt < k; ++i) {
		if (bs[i] == 1) {
			cout << i+1 << ' ';
			++cnt;
		}
	}
	cout << '\n';
}