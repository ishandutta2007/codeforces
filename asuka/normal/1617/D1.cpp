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
int T, n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		auto query = [](int a, int b, int c) -> int {
			cout << "? " << a <<  ' ' << b << ' ' << c << endl;
			int res; cin >> res;
			return res;
		};
		auto output = [](VI res) -> void{
			VI vec;
			rep(i, 1, n) if(res[i] == 0) vec.pb(i);
			cout << "! " << SZ(vec) << ' ';
			for(int x : vec) cout << x << ' ';
			cout << endl;
			return;
		};
		VI state(n / 3 + 1), ans(n + 1, -1);
		for(int i = 3; i <= n; i += 3) {
			state[i / 3] = query(i - 2, i - 1, i);
		}
		auto find = [&]() -> pii {
			rep(i, 1, n / 3) rep(j, 1, n / 3) if(state[i] == 0 && state[j] == 1) return mp(i * 3, j * 3);
		};
		int u, v, p0, p1, a[3], b[3];
		auto get = [&](int x) -> int {return query(p0, p1, x);};
		tie(u, v) = find();
		rep(i, 0, 2) a[i] = query(u - 2, u - 1, v - i), b[i] = query(v - 2, v - 1, u - i);
		if(*max_element(a, a + 2) == 1) {
			p0 = u; ans[u] = 0;
			rep(i, 0, 2) {
				ans[v - i] = a[i];
				if(a[i]) p1 = v - i;
			}
			ans[u - 2] = get(u - 2);
			ans[u - 1] = ans[u - 2] ^ 1;
		} else if(*min_element(b, b + 2) == 0) {
			p1 = v; ans[v] = 1;
			rep(i, 0, 2) {
				ans[u - i] = b[i];
				if(!b[i]) p0 = u - i;
			}
			ans[v - 2] = get(v - 2);
			ans[v - 1] = ans[v - 2] ^ 1;
		} else {
			p0 = u - 2; p1 = v - 2;
			ans[u - 1] = ans[u - 2] = 0;
			ans[v - 1] = ans[v - 2] = 1;
			ans[u] = get(u); ans[v] = get(v);
		}
		for(int i = 3; i <= n; i += 3) {
			if(~ans[i - 2] && ~ans[i - 1] && ~ans[i]) continue;
			if(state[i / 3] == 0) {
				int is01 = query(p1, i - 2, i - 1);
				if(is01) {
					ans[i] = 0;
					ans[i - 2] = get(i - 2);
					ans[i - 1] = ans[i - 2] ^ 1;
				} else {
					ans[i - 2] = ans[i - 1] = 0;
					ans[i] = get(i);
				}
			} else {
				int is01 = !query(p0, i - 2, i - 1);
				if(is01) {
					ans[i] = 1;
					ans[i - 2] = get(i - 2);
					ans[i - 1] = ans[i - 2] ^ 1;
				} else {
					ans[i - 2] = ans[i - 1] = 1;
					ans[i] = get(i);
				}
			}
		}
		output(ans);
	}
	return 0;
}