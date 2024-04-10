#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll maxid, ID[maxn], dp[4 * maxn];
vector <pair <ll, ll> > v[4 * maxn], g[4 * maxn];
set <pair <ll, ll> > s;
bool mark[4 * maxn];
void build (int id, int L, int R){
	maxid = max (maxid, 1ll * id + 1);
	if (L + 1 == R){
		ID[L] = id;
		return;
	}
	int mid = (L + R) / 2;
	g[id].PB (MP (2 * id + 0, 0));
	g[id].PB (MP (2 * id + 1, 0));
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	return;
}

void getedge (int id, int L, int R, int u, int l, int r, int w, bool heh){
	if (L == l and R == r){
		if (heh == 1)
			v[id].PB (MP (ID[u], w));
		else
			v[ID[u]].PB (MP (id, w));
		return;
	}
	int mid = (L + R) / 2;
	if (mid > l)
		getedge (2 * id + 0, L, mid, u, l, min (mid, r), w, heh);
	if (mid < r)
		getedge (2 * id + 1, mid, R, u, max (l, mid), r, w, heh);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, q, m;
	cin >> n >> q >> m;
	n ++;
	build (1, 1, n);
	for (int i = 1; i <= q; i++){
		int type;
		cin >> type;
		if (type == 1){
			ll u1, u2, w;
			cin >> u1 >> u2 >> w;
			v[ID[u1]].PB (MP (ID[u2], w));
		}
		else if (type == 2){
			ll u, l, r, w;
			cin >> u >> l >> r >> w;
			r ++;
			getedge (1, 1, n, u, l, r, w, 0);
		}
		else {
			ll u, l, r, w;
			cin >> u >> l >> r >> w;
			r ++;
			getedge (1, 1, n, u, l, r, w, 1);
		}
	}
	for (int i = 1; i <= 4 * n; i++)
		dp[i] = (1ll << 60);
	dp[ID[m]] = 0;
	for (int i = 1; i < maxid; i++)
		s.insert (MP (dp[i], i));
	while (!s.empty()){
		auto it = s.begin ();
		ll u = (*it).S;
		ll pok = (*it).F;
		s.erase (s.begin ());
//		cout << endl << pok << " " << u << " -> ";
//		cout << (s.find (MP (0, 4)) == s.end()) << " = ";
		for (auto w : g[u]){
			if (dp[w.F] > pok + w.S){
				s.erase (MP (dp[w.F], w.F));
				dp[w.F] = pok + w.S;
//				cout << dp[w.F] << " " << w.F << " - ";
				s.insert (MP (dp[w.F], w.F));
			}
		}
		if (mark[u] == 1){
			s.erase (MP (dp[u], u));
			continue;
		}
		while (u > 0){
			if (mark[u])
				break;
//			cout << u << " -> ";
			for (auto w : v[u]){
				if (dp[w.F] > pok + w.S){
					s.erase (MP (dp[w.F], w.F));
					dp[w.F] = pok + w.S;
					s.insert (MP (dp[w.F], w.F));
//					cout << dp[w.F] << " " << w.F << " -- ";
				}
			}
//			cout << endl;
			mark[u] = 1;
			u /= 2;
		}
//		for (int i = 1; i < maxid; i++)
//			if (g[i].size() != 0)
//				cout << dp[i] << " ";
//		cout << endl;
	}
	for (int i = 1; i < n; i++){
		if (dp[ID[i]] == (1ll << 60))
			dp[ID[i]] = -1;
		cout << dp[ID[i]] << " ";
	}
	cout << endl;
}