#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
 
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}
 
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ", "; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << ", " << P.second << ")";
}
 
#define LOCAL 
 
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
 
#define MAXN 1123
 
ll n, last;
 
ll tab[MAXN][MAXN];
 
map<pair<ll, ll>, ll> gettab;
 
ll get(ll i, ll x)
{
	if (gettab.find(pair<ll, ll>(i, x)) != gettab.end())
		return gettab[pair<ll, ll>(i, x)];
	ll retv = x;
	// assert(1 <= i && i <= n);
	// for (int j = 1; j <= 1; j++)
	// 	if (tab[i][j] <= x)
	// 		retv--;
	// return retv;
	// if (x > 5) return 5;
	// return x;
	cout << "? " << i << " " << x << endl;
	cin >> retv;
	return gettab[pair<ll, ll>(i, x)] = retv;
}
 
pair<ll, ll> ans[MAXN];
 
int pick(int a, int b)
{
	return a + (rand() % (b - a + 1));
}
 
 
ll find_fmid(int i, ll l, ll r, ll val)
{
	while (l != r)
	{
		ll mid = (l + r) / 2;
		if (get(i, mid) >= val)
			r = mid;
		else
			l = mid + 1;
	}
 
	return l;
}
 
ll split(ll l, ll r, ll prev, vector<int> pi, vector<int> &lpi, vector<int> &rpi)
{
	int a = 0, b = pi.size() - 1;
	int k = pi.size() / 2;
	ll xp;
	while (a != b)
	{
		assert(a <= k && k <= b);
		int pivot = pick(a, b);
		xp = find_fmid(pi[pivot], l, r, (prev + k) * (last / n));
		lpi.clear();
		rpi.clear();
		vector<int> eq;
		for (int i = a; i <= b; i++)
			if (i != pivot)
			{
				if (get(pi[i], xp) > (prev + k) * (last / n))
					lpi.push_back(pi[i]);
				else if (get(pi[i], xp) < (prev + k) * (last / n))
					rpi.push_back(pi[i]);
				else
					eq.push_back(pi[i]);
			}
		
		int bla = pi[pivot];
		int tmp = a;
		for (int i = 0; i < lpi.size(); i++)
			pi[tmp++] = lpi[i];

		for (int i = 0; i < eq.size(); i++)
			pi[tmp++] = eq[i];

		int breakpoint = tmp;
		pi[tmp++] = bla;
		for (int i = 0; i < rpi.size(); i++)
			pi[tmp++] = rpi[i];
 
		if (k > breakpoint)
		{
			a = breakpoint + 1;
		}
		else if (k < breakpoint - eq.size())
		{
			b = breakpoint - 1;
		}
		else
		{
			swap(pi[k], pi[breakpoint]);
			break;
		}
	}
 
	lpi.clear();
	rpi.clear();
 
	for (int i = 0; i < k; i++)
		lpi.push_back(pi[i]);
	for (int i = k; i < pi.size(); i++)
		rpi.push_back(pi[i]);
 
	return find_fmid(pi[k], l, r, (prev + k) * (last / n));
}
 
void solve(ll l, ll r, ll prev, vector<int> pi)
{
	if (pi.size() == 1)
	{
		ans[pi[0]] = {l, r};
		return;
	}
 
	vector<int> lpi, rpi;
	ll mid = split(l, r, prev, pi, lpi, rpi);
	solve(l, mid, prev, lpi);
	solve(mid, r, prev + lpi.size(), rpi);
}
 
int main(void)
{
	cin >> n >> last;
	while (true)
	{
		// for (int i = 1; i <= n; i++)
		// {
		// 	set<int> rdm;
		// 	for (int i = 0; i < 10 ; i++)
		// 		rdm.insert(pick(1, 10000));
		// 	auto it = rdm.begin();
		// 	for (int j = 1; j <= 1; j++)
		// 	{
		// 		tab[i][j] = (*it);
		// 		it++;
		// 	}
		// }
 
		vector<int> pi;
		for (int i = 1; i <= n; i++)
			pi.push_back(i);
 
		solve(0, 1e18, 0, pi);
 
		cout << "!" << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i].first << " " << ans[i].second << endl;
			// if (!(get(i, ans[i].second) - get(i, ans[i].first) >= (last / n)))
			// {
			// 	assert(get(i, ans[i].second) - get(i, ans[i].first) >= (last / n));
			// }
		}
 
		break;
	}
}