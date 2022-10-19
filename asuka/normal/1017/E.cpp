#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
struct P {int x, y;};
P operator - (const P &a, const P &b) {return (P) {a.x - b.x, a.y - b.y};}
ll operator & (const P &a, const P &b) {return (ll) a.x * b.y - (ll) a.y * b.x;}
ll operator * (const P &a, const P &b) {return (ll) a.x * b.x + (ll) a.y * b.y;}
bool operator < (const P &a, const P &b) {return a.x != b.x ? a.x < b.x : a.y < b.y;}
ll len(P o) {return (ll) o.x * o.x + (ll) o.y * o.y;}
ll angle(P a, P b, P c) {return (b - a) & (c - b);}
ll Angle(P a, P b, P c) {return (b - a) * (c - b);}
P read() {
	int x, y;
	scanf("%d%d", &x, &y);
	return (P) {x, y};
}
const int N = 200015;
int top, stk[N];
bool used[N];
vector<P> getHull(vector<P> a) {
	sort(all(a));
	int n = SZ(a);
	rep(i, 0, n - 1) used[i] = 0;
	top = 0;
	stk[++top] = 0;
	rep(i, 1, n - 1) {
		while(top >= 2 && angle(a[stk[top - 1]], a[stk[top]], a[i]) <= 0) used[stk[top--]] = 0;
		stk[++top] = i;
		used[i] = 1;
	}
	int tmp = top;
	per(i, 0, n - 1) {
		if(used[i]) continue;
		while(top > tmp && angle(a[stk[top - 1]], a[stk[top]], a[i]) <= 0) used[stk[top--]] = 0;
		stk[++top] = i;
		used[i] = 1;
	}
	vector<P> res;
	rep(i, 1, top - 1) res.pb(a[stk[i]]);
	return res;
}
vector<ll> getSequence(vector<P> a, bool flag) {
	int n = SZ(a);
	if(flag) {
		rep(i, 0, n - 1) a.pb(a[i]);
		n <<= 1;
	}
	vector<ll> res;
	rep(i, 0, n - 1) {
		res.pb(Angle(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]));
		res.pb(len(a[i] - a[(i - 1 + n) % n]));
	}
	return res;
}
VI getBorder(vector<ll> s) {
	int n = SZ(s);
	VI border(n);
	rep(i, 1, n - 1) {
		int j = border[i - 1];
		while(j > 0 && s[j] != s[i]) j = border[j - 1];
		if(s[i] == s[j]) j++;
		border[i] = j;
	}
	return border;
}
bool match(vector<ll> s, vector<ll> t) {
	VI border = getBorder(t);
	int n = SZ(s), m = SZ(t);
	int j = 0;
	rep(i, 0, n - 1) {
		while(j > 0 && t[j] != s[i]) j = border[j - 1];
		if(t[j] == s[i]) j++;
		if(j == m) return 1;		
	}
	return 0;
}
int n, m;
vector<P> a, b;
int main() { 
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) a.pb(read());
	rep(i, 1, m) b.pb(read());
	a = getHull(a);
	b = getHull(b);
	auto sa = getSequence(a, 1), sb = getSequence(b, 0);
	bool ans = SZ(a) == SZ(b) ? match(sa, sb) : 0;
	puts(ans ? "YES" : "NO");
	return 0;
}