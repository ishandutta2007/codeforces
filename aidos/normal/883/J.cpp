#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"


int n, m;
int a[100100];
pair < pair<int, int>, int> b[100100];

ll C[100100];

ll t[400400];


void build(int v, int l, int r){
	if(l == r){
		t[v] = C[l];
	}
	else{
		int mid= (l+r)>>1;
		build(v * 2, l, mid);
		build(v * 2 + 1, mid+1, r);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

ll get(int v, int l, int r, int tl, int tr){
	if(tl > r || l>tr) return 0;
	if(tl <= l && r <= tr){
		return t[v];
	}
	int mid=(l+r)>>1;
	return get(v * 2, l, mid, tl, tr) + get(v * 2 + 1, mid+1, r, tl, tr);
}

void upd(int v, int l, int r, int tl, int tr, int &x){
	if(x == 0) return;
	if(t[v] == 0) return;
	if(l > tr || tl > r) return;
	if(l == r){
		int k = min(x*1ll, t[v]);
		x-=k;
		t[v]-=k;
		return;
	}
	int mid = (l + r)>>1;
	upd(v * 2 + 1, mid+1, r, tl, tr, x);
	upd(v * 2, l, mid, tl, tr, x);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i].f.s);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i].f.f);
		b[i].s = i;
	}
	vector<int> v; 
	for(int i = 0; i < n; i++){
		ll cur = a[i];
		while(v.size() > 0 && v.back() <= a[i]){
			v.pop_back();
			cur += C[v.size()];
		}

		C[v.size()] = cur;
		v.pb(a[i]);
	}
	n = v.size();
	build(1, 0, n-1);
	reverse(all(v));
	sort(b, b + m);
	int ans = 0;

	for(int i = 0; i < m; i++){
		int pos = lower_bound(all(v), b[i].f.s) - v.begin();
		if(pos == n) continue;
		if(get(1, 0, n-1, 0, n-pos-1) >= b[i].f.f){
			int x = b[i].f.f;
			upd(1, 0, n-1, 0, n-pos-1, x);
			ans++;
		}
	}
   
	cout << ans << endl;


	return 0;
}