// vaziat meshki-ghermeze !
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

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
ll ps[N];

ll mn[N << 2], mx[N << 2];
void Build(int id, int L, int R){
	if(L + 1 == R){
		mn[id] = ps[L];
		mx[id] = ps[L];
		return ;
	}
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id<<1|1, mid, R);
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
}
ll Min(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return Inf;
	if(l <= L && R <= r) return mn[id];
	int mid = (L + R) >> 1;
	return min(Min(id << 1, l, r, L, mid), Min(id << 1 | 1, l, r, mid, R));
}
ll Max(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return -Inf;
	if(l <= L && R <= r) return mx[id];
	int mid = (L + R) >> 1;
	return max(Max(id << 1, l, r, L, mid), Max(id << 1 | 1, l, r, mid, R));
}

int Main(){
	ll n, v, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> v;
		a[i] = -v;
	}
	for(int i = 0; i < n; i++){
		cin >> v;
		a[i] += v;
	}
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i - 1];
	Build(1, 0, n + 1);
	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		l --;
		if(ps[l] != ps[r]){
			cout << "-1\n";
			continue;
		}
		ll rs = Min(1, l, r + 1, 0, n + 1) - ps[l];
		if(rs < 0){
			cout << "-1\n";
			continue;
		}
		cout << Max(1, l, r + 1, 0, n + 1) - ps[l] << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}