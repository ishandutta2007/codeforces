// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 3e5 + 10;
const int Inf = 1e9;
const ll Log = 30;

int n, q;
int a[N];
vector<int> seg[N << 2];
void Build(int id, int L, int R){
	//cerr << "# " << L << ' ' << R << '\n';
	seg[id].resize(R - L + 1);
	if(L + 1 == R){
		if(a[L] <= L) seg[id][0] = L - a[L];
		else seg[id][0] = n + 1;
		seg[id][1] = Inf;
		return ;
	}
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);

	int p = 0;
	int sm = 0, p1 = 0, p2 = 0, sm2 = 0, d;
	int lc = id << 1;
	int rc = lc + 1;
	while(p < ((int) seg[id].size()) - 1){
		d = min(seg[lc][p1] - sm, seg[rc][p2] - sm2);
		sm += d;
		sm2 += d;
		while(seg[lc][p1] <= sm){
			sm2 ++;
			p1 ++;
			seg[id][p] = sm; p++;
		}
		while(seg[rc][p2] <= sm2){
			p2 ++;
			seg[id][p] = sm; p++;
		}
	}
	seg[id][p] = Inf;
	//cerr << L << ' ' << R << " -> ";
	//for(auto x : seg[id]) cerr << x << ' ';
	//cerr << '\n';
}

int poi, res;
int tmp;
void Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		tmp = upper_bound(all(seg[id]), poi) - seg[id].begin();
		poi += tmp;
		return ;
	}
	int mid = (L + R) >> 1;
	Get(id << 1, l, r, L, mid);
	Get(id << 1 | 1, l, r, mid, R);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Build(1, 1, n + 1);
	//debug("F");
	int x, y;
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		poi = 0;
		Get(1, 1 + x, n + 1 - y, 1, n + 1);
		cout << poi << '\n';
	}
	return 0;
}