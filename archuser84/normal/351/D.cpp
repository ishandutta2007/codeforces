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

const int N = 100'010;
const int S = 320;
vector<tuple<int,int,int>> Q[(N+S)/S];
int a[N];
int ans[N];
int n, q;

int cnt0, cnt1;
int cnt[N];
int qu[N], fst[N], lst[N]; // -2: fail, -1: single, 0: none

vector<tuple<int,int,int,int,int,int,int>> his;

void add(int i, bool side)
{
	if (!side)
		his.emplace_back(cnt0, cnt1, a[i], cnt[a[i]], qu[a[i]], fst[a[i]], lst[a[i]]);
	cnt0 += !cnt[a[i]];
	cnt[a[i]]++;
	if (qu[a[i]] == 0) {
		cnt1++;
		qu[a[i]] = -1;
		fst[a[i]] = lst[a[i]] = i;
	} else if (qu[a[i]] == -1) {
		fst[a[i]] = min(fst[a[i]], i);
		lst[a[i]] = max(lst[a[i]], i);
		qu[a[i]] = lst[a[i]] - fst[a[i]];
	} else if (qu[a[i]] != -2) {
		if (side) {
			if (i-lst[a[i]] != qu[a[i]]) {
				qu[a[i]] = -2;
				--cnt1;
			}
			lst[a[i]] = i;
		} else {
			if (fst[a[i]]-i != qu[a[i]]) {
				qu[a[i]] = -2;
				--cnt1;
			}
			fst[a[i]] = i;
		}
	}
}

void revert()
{
	reverse(his.begin(), his.end());
	for (auto [i0, i1, i2, i3, i4, i5, i6] : his) {
		cnt0 = i0;
		cnt1 = i1;
		cnt[i2] = i3;
		qu[i2] = i4;
		fst[i2] = i5;
		lst[i2] = i6;
	}
	his.clear();
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n)
		cin >> a[i];
	cin >> q;
	Loop (i,0,q) {
		int l, r;
		cin >> l >> r;
		--l;
		Q[l/S].push_back({r, l, i});
	}
	Loop (i,0,(N+S)/S) {
		sort(Q[i].begin(), Q[i].end());
		cnt0 = cnt1 = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(qu, 0, sizeof(qu));
		int R = i*S;
		for (auto [r, l, qi] : Q[i]) {
			while (R < r) {
				if (R >= (i+1)*S)
					add(R, 1);
				++R;
			}
			int L = min((ll)R, (i+1)*S);
			int hlp = cnt0;
			while (L > l) {
				--L;
				add(L, 0);
			}
			ans[qi] = cnt0 + !cnt1;
//			cout << i << ' ' << cnt0 << ' ' << cnt1 << '\n';
			revert();
		}
	}
	Loop (i,0,q)
		cout << ans[i] << '\n';
}