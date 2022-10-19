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

const int N = 500'010;
int fen[N];
int n;

int get(int r)
{
	int ans = 0;
	while (r) {
		ans = max(ans, fen[r]);
		r -= r&-r;
	}
	return ans;
}
void up(int i, int x)
{
	++i;
	while (i <= n) {
		fen[i] = max(fen[i], x);
		i += i & -i;
	}
}

void solve()
{
	cin >> n; ++n;
	vector<int> st;
	vector<int> *pre = new vector<int>[n];
	int *a = new int[n]{};
	int *b = new int[n]{};
	Loop (i,1,n)
		cin >> a[i];
	LoopR (i,0,n) {
		while (st.size() && a[i] >= a[st.back()])
			st.pop_back();
		if (st.size())
			pre[st.back()].push_back(i);
		st.push_back(i);
	}
	memset(fen, 0, sizeof(fen[0]) * (n+1));
	Loop (i,0,n) {
		int x = get(a[i]+1);
		up(a[i], x+1);
		b[i] = x+1;
		for (int j : pre[i]) {
			++b[j];
			up(a[j], b[j]);
		}
	}
	cout << get(n)-1 << '\n';
	delete[](a);
	delete[](b);
	delete[](pre);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
		solve();
}