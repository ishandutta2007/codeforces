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

const int N = 300'010;
int a[N];
int n;

struct node {
	ll lzy;
	ll l, r;
	int ld, rd;
	int lh, rh;
	int mx;
} t[N<<2];

void tag(int i, ll x)
{
	t[i].lzy += x;
	t[i].l += x;
	t[i].r += x;
}

void ppg(int i)
{
	tag(2*i+1, t[i].lzy);
	tag(2*i+2, t[i].lzy);
	t[i].lzy = 0;
}

void merge(int i, int b, int e)
{
	int szl = (e-b)/2, szr = (e-b+1)/2;

	t[i].l = t[2*i+1].l;

	t[i].r = t[2*i+2].r;

	t[i].ld = t[2*i+1].ld == szl && t[2*i+1].r > t[2*i+2].l?
	          szl + t[2*i+2].ld: t[2*i+1].ld;

	t[i].rd = t[2*i+2].rd == szr && t[2*i+1].r < t[2*i+2].l?
	          t[2*i+1].rd + szr: t[2*i+2].rd;

	t[i].lh = t[2*i+1].lh == szl && t[2*i+1].r > t[2*i+2].l?
	          szl + t[2*i+2].ld: t[2*i+1].lh;
	t[i].lh = t[2*i+1].rd == szl && t[2*i+1].r < t[2*i+2].l?
	          max(t[i].lh, szl + t[2*i+2].lh): t[i].lh;

	t[i].rh = t[2*i+2].rh == szr && t[2*i+1].r < t[2*i+2].l?
	          t[2*i+1].rd + szr: t[2*i+2].rh;
	t[i].rh = t[2*i+2].ld == szr && t[2*i+1].r > t[2*i+2].l?
	          max(t[i].rh, t[2*i+1].rh + szr): t[i].rh;

	t[i].mx = max(t[2*i+1].mx, t[2*i+2].mx);
	if (t[2*i+1].r < t[2*i+2].l)
		t[i].mx = max(t[i].mx, t[2*i+1].rd + t[2*i+2].lh);
	if (t[2*i+1].r > t[2*i+2].l)
		t[i].mx = max(t[i].mx, t[2*i+1].rh + t[2*i+2].ld);
}



void build(int i=0, int b=0, int e=n)
{
	t[i].lzy = 0;
	if (e-b == 1) {
		t[i].mx = t[i].ld = t[i].lh = t[i].rd = t[i].rh = 1;
		t[i].l = t[i].r = a[b];
		return;
	}
	build(2*i+1,b,(b+e)/2);
	build(2*i+2,(b+e)/2,e);
	merge(i,b,e);
	//cout << b << ' ' << e << " -> " << t[i].mx << '\n';
}

void add(int l, int r, int x, int i=0, int b=0, int e=n)
{
	if (l <= b && e <= r) return tag(i, x);
	if (r <= b || e <= l) return;
	ppg(i);
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
	merge(i,b,e);
	//cout << b << ' ' << e << " -> " << t[i].mx << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n)
		cin >> a[i];
	build();
	int q;
	cin >> q;
	while (q--) {
		int l, r, d;
		cin >> l >> r >> d;
		--l;
		add(l, r, d);
		cout << t[0].mx << '\n';
	}
}