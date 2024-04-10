#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 200'010;

namespace seg
{
	int t[N << 2] = {};
	int lzy[N << 2] = {};

	inline void ppg(int i, int b, int e)
	{
	    if(lzy[i] == 1) t[2*i+1] = t[2*i+2] = 0, lzy[2*i+1] = lzy[2*i+2] = 1;
	    if(lzy[i] == 2) t[2*i+1] = (e-b)/2, t[2*i+2] = (e-b+1)/2, lzy[2*i+1] = lzy[2*i+2] = 2;
	    lzy[i] = 0;
	}

	int get(int i, int l, int r, int b, int e)
	{
		if(l <= b && e <= r) return t[i];
		if(r <= b || e <= l) return 0;
		ppg(i, b, e);
		return get(2*i+1, l, r, b, (b+e)/2) +
                get(2*i+2, l, r, (b+e)/2, e);
	}

	void set(int i, bool v, int l, int r, int b, int e)
	{
		if(l <= b && e <= r) {t[i] = (e-b)*v; lzy[i] = 1+v; return;}
		if(r <= b || e <= l) return;
		ppg(i, b, e);
		set(2*i+1, v, l, r, b, (b+e)/2);
		set(2*i+2, v, l, r, (b+e)/2, e);
		t[i] = t[2*i+1] + t[2*i+2];
	}

};

void solve()
{
    int n, q;
    string s, f;
    vector<pii> Q;
    cin >> n >> q;
    cin >> s >> f;
    while(q--)
    {
        int x, y;
        cin >> x >> y; x--;
        Q.emplace_back(x, y);
    }
    reverse(all(Q));
    Loop(i,0,n) seg::set(0, f[i]-'0', i, i+1, 0, n);
    for(auto q : Q)
    {
        int sz = q.S - q.F;
        int x = seg::get(0, q.F, q.S, 0, n);
        //cerr << x << ' ' << sz << '\n';
        if(sz == 2*x) {cout << "NO\n"; return;}
        if(2*x < sz) seg::set(0, 0, q.F, q.S, 0, n);
        else         seg::set(0, 1, q.F, q.S, 0, n);
    }
    Loop(i,0,n) if(seg::get(0, i, i+1, 0, n) != s[i]-'0') {cout << "NO\n"; return;}
    cout << "YES\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}