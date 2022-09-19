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
// const ll Inf = 2242545357980376863LL;
// const ll Log = 30;
const int SQ = 400;

struct DS {
	int sz;
	int a[N];
	
	int p = 0, sm = 0;

	void Init(int x){
		sz = x;
	}
	void Go(){
		if(p == sz - 1){
			p = 0;
			sm = a[0];
			return ;
		}
		p ++;
		sm += a[p];
	}
	void Add(int idx, int x){
		a[idx] += x;
		if(idx <= p)
			sm += x;
	}
	int Get(){
		return sm;
	}
};
DS ds[SQ + 10];

int x[N], y[N];
int mk[N];
int ad[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		x[i] = min(x[i], m);
		y[i] = min(y[i], m);
	}
	int tot = SQ + 1;
	for(int i = 2; i <= SQ; i++) ds[i].Init(i);
	ds[tot].Init(m + 4);

	int t, i;
	for(int k = 0; k < m; k++){
		cin >> t >> i;
		int z;
		if(mk[i]) z = -1;
		else z = 1;
		if(x[i] + y[i] > SQ){
			int u = (mk[i] ? ad[i] : k);
			for(int p = u; p < m; p += x[i] + y[i]){
				ds[tot].Add(min(m + 2, p + x[i]), +1 * z);
				ds[tot].Add(min(m+2,p+x[i]+y[i]), -1 * z);
			}
		} else {
			int id = x[i] + y[i];
			int u = (mk[i] ? ad[i] : k);
			int l = u + x[i];
			int r = u + id;
			l %= id;
			r %= id;
			// cerr << "!! " << l << ' ' << r << ' ' << ds[3].p << '\n';
			if(l < r){
				ds[id].Add(l, +1 * z);
				ds[id].Add(r, -1 * z);
			} else {
				ds[id].Add(0, +1 * z);
				ds[id].Add(id,-1 * z);
				ds[id].Add(r, -1 * z);
				ds[id].Add(l, +1 * z);
			}
		}
		mk[i] ^= 1;
		if(mk[i] == 1)
			ad[i] = k;
		int ans = 0;
		for(int u = 0; u <= tot; u++)
			ans += ds[u].Get();
		cout << ans << '\n';
		for(int u = 2; u <= tot; u++) ds[u].Go();
	}
	return 0;
}