#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 400032;

int a[N];
int a2[N], a2s = 0;
int pnt_to[N];
int last_t1[N];
vector<int> cmp;
bool has_a[N];
bool has_q[N];
struct { int t, a, b; } q[N];
int n, t;

__attribute__((optimize("O3,unroll-loops"),target("avx2")))
void update_a2(int l, int r)
{
	int m = (l + r + 1)/2;
	for (int i = 0; i < a2s; ++i) {
		int x = a2[i];
		int tmp = -(l < x && x < r);
		a2[i] ^= (a2[i] ^ (x < m? l: r)) & tmp;
	}
}

__attribute__((optimize("O3,unroll-loops"),target("avx2")))
void update_a(int l, int r)
{
	int m = (l + r + 1)/2;
	int x = upper_bound(a, a+n, l) - a;
	int y = lower_bound(a, a+n, m) - a;
	int z = lower_bound(a, a+n, r) - a;
	Loop (i,x,y)
		a[i] = l;
	Loop (i,y,z)
		a[i] = r;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n)
		cin >> a[i];
	cin >> t;
	memset(last_t1, -1, sizeof(last_t1));
	Loop (i,0,t) {
		cin >> q[i].t;
		switch (q[i].t) {
		case 1:
			cin >> q[i].a >> q[i].b;
			--q[i].a;
			last_t1[q[i].a] = i;
			break;
		case 2:
			cin >> q[i].a;
			--q[i].a;
			if (last_t1[q[i].a] == -1)
				has_a[q[i].a] = 1;
			else
				has_q[last_t1[q[i].a]] = 1;
			break;
		case 3:
			cin >> q[i].a >> q[i].b;
			--q[i].a; ++q[i].b;
			break;
		}
	}
	Loop (i,0,n) {
		if (has_a[i])
			cmp.push_back(a[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	Loop (i,0,n) {
		if (has_a[i])
			pnt_to[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin();
		else
			pnt_to[i] = -1;
	}
	n = cmp.size();
	Loop (i,0,n)
		a[i] = cmp[i];
	Loop (i,0,t) {
		switch (q[i].t) {
		case 1:
			if (has_q[i]) {
				a2[a2s] = q[i].b;
				pnt_to[q[i].a] = a2s + n;
				a2s++;
			}
			break;
		case 2:
			if (pnt_to[q[i].a] < n)
				cout << a[pnt_to[q[i].a]] << '\n';
			else
				cout << a2[pnt_to[q[i].a] - n] << '\n';
			break;
		case 3:
			update_a(q[i].a, q[i].b);
			update_a2(q[i].a, q[i].b);
			break;
		}
	}		
}