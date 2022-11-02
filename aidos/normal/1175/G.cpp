#include<bits/stdc++.h>

using namespace std;

#define fo(i, n) for(int i = 1; i <= n; ++i)
#define mp make_pair
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 20200;
const int mod = 1e9 + 7;
const ll inf = 1e12;

int n, k, a[N], l[N], r[N], st[N], sz;
ll dp[103][N];

struct line {
	ll k, b;
	line() {}
	line(ll K, ll B) {k = K, b = B;}
};

vector<line> t[4*N], g[4*N];
int post[4*N];
int posg[4*N];

inline bool better(line a, line b, line c) {
    long double d1 = 0;
	return (d1 + a.b - c.b) * (b.k - a.k) <= (d1 + a.b - b.b) * (c.k - a.k);
}

inline void add(vector<line> &t, line x)
{
	while(t.size() > 1 && better(t[t.size() - 2], t[t.size() - 1], x))
		t.pop_back();
	t.emplace_back(x);
}

inline ll get_val(line a, ll x)
{
	return a.k * x + a.b;
}

inline void update_post(int v, ll x)
{
	if(post[v] > int(t[v].size()) - 1)
		post[v] = int(t[v].size()) - 1;
	while(post[v] + 1 < t[v].size() && get_val(t[v][post[v] + 1], x) <= get_val(t[v][post[v]], x))
		post[v]++;
}

inline void update_posg(int v, ll x)
{
	if(posg[v] > int(g[v].size()) - 1)
		posg[v] = int(g[v].size()) - 1;
	while(posg[v] + 1 < g[v].size() && get_val(g[v][posg[v] + 1], x) >= get_val(g[v][posg[v]], x))
		posg[v]++;
}

inline ll get_valt(int v, ll x)
{
	if(t[v].empty() == true) return inf;
	update_post(v, x);
	return get_val(t[v][post[v]], x);
}

inline ll get_valg(int v, ll x)
{
	if(g[v].empty() == true) return -inf;
	update_posg(v, x);
	return get_val(g[v][posg[v]], x);
}

inline void upd(int v, int tl, int tr, int l, int r, line x)
{
	if(l > r) return;
	if(tl == l && tr == r)
	{
		add(t[v], x);
		return;
	}
	int tm = tl + tr >> 1;
	upd(v + v, tl, tm, l, min(r, tm), x);
	upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
}

inline ll calc(int v, int tl, int tr, ll x)
{
	ll cur = get_valt(v, x);
	if(tl == tr)
		return cur;
	int tm = tl + tr >> 1;
	if(x <= tm)
		return min(cur, calc(v + v, tl, tm, x));
	else
		return min(cur, calc(v + v + 1, tm + 1, tr, x));
}

inline void upd_get(int v, int tl, int tr, int p, line x)
{
	add(g[v], x);
	if(tl == tr) return;
	int tm = tl + tr >> 1;
	if(p <= tm)
		upd_get(v + v, tl, tm, p, x);
	else
		upd_get(v + v + 1, tm + 1, tr, p, x);
}

inline ll get(int v, int tl, int tr, int l, int r, ll x)
{
	if(l > r) return -inf;
	if(tl == l && tr == r)
		return get_valg(v, x);
	int tm = tl + tr >> 1;
	return max(get(v + v, tl, tm, l, min(r, tm), x), get(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x));
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	sz = 0;
	ll sum = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], sum += a[i];

	st[0] = 0;
	for(int i = 1; i <= n; ++i)	
	{
		while(sz > 0 && a[i] >= a[st[sz]]) --sz;
		l[i] = st[sz];		
		st[++sz] = i;
	}
	
	sz = 0;
	st[0] = n + 1;
	for(int i = n; i >= 1; --i)
	{
		while(sz > 0 && a[i] >= a[st[sz]]) --sz;
		r[i] = st[sz];
		st[++sz] = i;
	}

	for(int j = 0; j <= k; ++j)
	{
		for(int i = 0; i <= n; ++i)
			dp[j][i] = inf;
		dp[j][0] = 0;
	}
	
	for(int j = 1; j <= k; ++j)
	{
		for(int i = 1; i <= 4 * (n+1); ++i)
			t[i].clear(), g[i].clear(), post[i] = 0, posg[i] = 0;
		for(int i =	0; i <= n; ++i)
		{
			if(i)
			{
				ll val = -get(1, 0, n, l[i], i, a[i]);
				line v = line(a[i], val);
				if(val != inf) upd(1, 0, n, i, r[i] - 1, v); 
			}
			if(dp[j - 1][i] != inf) upd_get(1, 0, n, i, line(i, -dp[j-1][i]));
		}	
		for(int i = 0; i <= n; ++i)
			dp[j][i] = min(dp[j-1][i], calc(1, 0, n, i));
	}
	
	cout << dp[k][n]  << '\n';
	
	return 0;
}