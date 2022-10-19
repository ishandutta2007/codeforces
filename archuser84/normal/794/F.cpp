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
const int DIG = 10;
typedef array<ll, DIG> vec;
int a[N];
int n, q;

vec seg[N<<2];
vec lzy[N<<2];

void add(vec &a, const vec &b, const vec &c) {Loop (i,0,DIG) a[i] = b[i] + c[i];}

void init(int i=0, int b=0, int e=N)
{
	Loop (j,0,DIG) lzy[i][j] = j;
	if (e - b == 1) {
		for (int x = a[b], y = 1; x; x /= 10, y *= 10)
			seg[i][x%10] += y;
		return;
	}
	init(2*i+1,b,(b+e)/2);
	init(2*i+2,(b+e)/2,e);
	add(seg[i], seg[2*i+1], seg[2*i+2]);
}

void tag(int i, const vec &v)
{
	vec &t = seg[i];
	vec &l = lzy[i];
	vec tmp = {};
	Loop (j,0,DIG) {
		tmp[v[j]] += t[j];
		l[j] = v[l[j]];
	}
	t = tmp;
}

void ppg(int i)
{
	tag(2*i+1, lzy[i]);
	tag(2*i+2, lzy[i]);
	Loop (j,0,DIG) lzy[i][j] = j;
}

vec get(int l, int r, int i=0, int b=0, int e=N)
{
	if (l <= b && e <= r) return seg[i];
	vec ans = {};
	ppg(i);
	if (l < (b+e)/2) add(ans, ans, get(l,r,2*i+1,b,(b+e)/2));
	if ((b+e)/2 < r) add(ans, ans, get(l,r,2*i+2,(b+e)/2,e));
	return ans;
}

void up(int l, int r, const vec &v, int i=0, int b=0, int e=N)
{
	if (l <= b && e <= r) return tag(i, v);
	ppg(i);
	if (l < (b+e)/2) up(l,r,v,2*i+1,b,(b+e)/2);
	if ((b+e)/2 < r) up(l,r,v,2*i+2,(b+e)/2,e);
	add(seg[i], seg[2*i+1], seg[2*i+2]);
}

ll getx(int l, int r)
{
	vec tmp = get(l, r);
	ll ans = 0;
	Loop (i,0,DIG)
		ans += tmp[i]*i;
	return ans;
}

void upxy(int l, int r, int x, int y)
{
	vec tmp;
	Loop (j,0,DIG) tmp[j] = j;
	tmp[x] = y;
	up(l,r,tmp);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);;
	cin >> n >> q;
	Loop (i,0,n) cin >> a[i];
	init();
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r; --l;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			upxy(l, r, x, y);
		} else {
			cout << getx(l, r) << '\n';
		}
	}
}