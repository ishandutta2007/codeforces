#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
using db = double;
int n, m, a[N], b[N], z[N], h[N], l[N], r[N];
struct Event {
	int x, v, typ;
};
vector<Event> event;
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d%d%d%d", &a[i], &h[i], &l[i], &r[i]);
	rep(i, 1, m) scanf("%d%d", &b[i], &z[i]);
	rep(i, 1, n) {
		event.pb((Event){a[i] - h[i], 100 - l[i], 1});
		event.pb((Event){a[i], 100 - l[i], -1});
		event.pb((Event){a[i] + 1, 100 - r[i], 1});
		event.pb((Event){a[i] + h[i] + 1, 100 - r[i], -1});
	}
	rep(i, 1, m) {
		event.pb((Event){b[i], i, 2});
	}
	sort(all(event), [](Event a, Event b) {
		return a.x != b.x ? a.x < b.x : a.typ < b.typ;
	});
	db ans = 0;
	multiset<int> S;
	for(auto u : event) {
		if(u.typ == 2) {
			db tmp = z[u.v];
			if(SZ(S) <= 5000) {
				for(auto x : S) tmp *= (db) x / 100.0;
				ans += tmp;
			}
		} else {
			if(u.typ == 1) {
				if(u.v != 100) 
					S.insert(u.v);
			} else {
				if(u.v != 100)
					S.erase(S.find(u.v));
			}
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}