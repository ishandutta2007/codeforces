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

const int N = 300'010;
const int inf = 1e9+10;
vector<pii> ch[N];
set<pii> s;
int a[N], b[N];
int n, k;

int cnt[N];
pll count(int x)
{
	memset(cnt, 0, sizeof(cnt));
	int j = 0, cntji = 0;
	pll ans = {};
	ll sumh = 0;
	Loop (i,0,n) {
		for (auto [c, x] : ch[i]) {
			if (c < j) {
				cntji += x;
				sumh -= (ll)x * (c+1);
			}
			if (c >= 0)
				cnt[c] -= x;
			cnt[i] += x;
		}
		while (cntji > x) {
			cntji -= cnt[j];
			sumh += (ll)cnt[j] * (j+1);
			++j;
		}
		ans.first += j;
//		cout << j << i << "!\n";
//		cout << cnt[0] << cnt[1] << "-\n";;
//		cout << cntji << ' ' << sumh << " ?\n";
		ans.second += sumh + (ll)cntji*j;
	}
	return ans;
}

void insert(int i, int x)
{
	auto it = s.lower_bound({i, -10});
	if (it->first == i)
		s.erase(it);
	s.insert({i,x});
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop (i,0,n)
		cin >> a[i] >> b[i];
	s.insert({0, -1});
	s.insert({inf, -2});
	Loop (i,0,n) {
		auto it = s.upper_bound({a[i],inf});
		auto it2 = it; --it2;
		int col = it2->second;
		ch[i].push_back({it2->second, min(b[i], it->first) - a[i]});
//		cout << b[i] << ' ' << it->first << "\\\n";
		insert(a[i], i);
		while (it->first <= b[i]) {
			it2 = it++;
			ch[i].push_back({it2->second, min(b[i], it->first) - it2->first});
			col = it2->second;
			s.erase(it2);
		}
		insert(b[i], col);
	}
//	Loop (i,0,n) {
//		cout << i << ": ";
//		for (auto [c, x] : ch[i])
//			cout << "("<<c<<", "<<x<<")\n";
//	}
	int l = 0, r = inf;
	while (l < r) {
		int mid = (l+r)/2;
		if (count(mid).first > k)
			l = mid+1;
		else
			r = mid;
	}
	pll ans = count(l);
//	cout << l << ' ' << ans.first << ' ' << ans.second << '\n';
	ll fans = ans.second + (k-ans.first)*l;
	cout << fans << '\n';
}