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

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int cnt[2] = {};
	string s;
	cin >> s;
	int n = s.size();
	Loop (i,0,n)
		cnt[s[i]-'(']++;
	vector<int> v1 = sort_cyclic_shifts(s);
	vector<int> v2(n);
	vector<int> val(n), mnpre(n+1), mnsuf(n+1);
	Loop (i,0,n)
		v2[v1[i]] = i;
	int cur = 0;
	Loop (i,0,n) {
		val[i] = cur;
		cur += s[i]=='('? 1: -1;
	}
	mnsuf[n] = 1e9;
	mnpre[0] = 1e9;
	Loop (i,0,n) mnpre[i+1] = min(mnpre[i], val[i]);
	LoopR (i,0,n) mnsuf[i] = min(mnsuf[i+1], val[i]);
	int pre = max(cnt[1]-cnt[0], 0);
	int ans = -1;
	Loop (i,0,n) {
		if (mnsuf[i]-val[i]+pre < 0)
			continue;
		if (mnpre[i]+(cnt[0]-cnt[1])-val[i]+pre < 0)
			continue;
		if (ans == -1 || v2[ans] > v2[i])
			ans = i;
	}
	assert(ans != -1);
	Loop (i,0,cnt[1]-cnt[0])
		cout << '(';
	Loop (i,0,n)
		cout << s[(i+ans)%n];
	Loop (i,0,cnt[0]-cnt[1])
		cout << ')';
	cout << '\n';
}