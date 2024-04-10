#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, stc[N], top;
pair <int, int> p[N << 1];
map <pair <int, int>, int> mp;
set <int> s;
vector <int> rg[N];
int R, mx[N], vis[N], sz[N], label[N];
vector <int> g[N];
void findroot(int id, int fa, int tot) {
	mx[id] = 0, sz[id] = 1;
	for(int it : g[id]) {
		if(it == fa || vis[it]) continue;
		findroot(it, id, tot);
		sz[id] += sz[it], mx[id] = max(mx[id], sz[it]);
	}
	mx[id] = max(mx[id], tot - sz[id]);
	if(mx[R] > mx[id]) R = id;
}
void findsize(int id, int fa) {
	sz[id] = 1;
	for(int it : g[id]) if(it != fa && !vis[it]) findsize(it, id), sz[id] += sz[it];
}
void divide(int id) {
	vis[id] = 1;
	for(int it : g[id]) {
		if(vis[it]) continue;
		findsize(it, id); // ADD THIS LINE
		R = 0, findroot(it, id, sz[it]);
		label[R] = label[id] + 1, divide(R);
	}
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n >> m;
	mx[0] = n;
	for(int i = 1; i <= n; i++) s.insert(i);
	for(int i = 1, x, y, cnt = 0; i <= m; i++) {
		cin >> x >> y;
		if(x > y) swap(x, y);
		p[++cnt] = {x, 1}, p[++cnt] = {y, 0};
	}
	sort(p + 1, p + m * 2 + 1);
	for(int i = 1, cnt = 0; i <= m * 2; i++) {
		int id = p[i].first;
		if(p[i].second) {stc[++top] = id; continue;}
		int l = stc[top--];
		// cerr << l << " " << id << endl;
		rg[++cnt].push_back(l), rg[cnt].push_back(id);
		while(1) {
			// cerr << l << " " << r << " " << *--s.end() << endl;
			auto it = s.upper_bound(l);
			assert(it != s.end());
			if(*it == id) break;
			rg[cnt].push_back(*it), s.erase(it);
		}
	}
	m++;
	while(!s.empty()) rg[m].push_back(*--s.end()), s.erase(--s.end());
	for(int i = 1; i <= m; i++) sort(rg[i].begin(), rg[i].end()), reverse(rg[i].begin(), rg[i].end());
	// for(int i = 1; i <= m; i++) {
	// 	cerr << "chk " << i << " : ";
	// 	for(int it : rg[i]) cerr << it << " ";
	// 	cerr << endl;
	// }
	sort(rg + 1, rg + m + 1);
	for(int i = 1; i <= m; i++) {
		// cerr << "chk " << i << " : ";
		// for(int it : rg[i]) cerr << it << " ";
		// cerr << endl;
		for(int j = 0; j < rg[i].size(); j++) {
			int x = rg[i][j], y = j ? rg[i][j - 1] : rg[i].back();
			if(x > y) swap(x, y);
			if(x == 1 && y == n || x + 1 == y) continue;
			// cerr << "chk " << x << " " << y << endl;
			auto it = mp.find(make_pair(x, y));
			if(it == mp.end()) mp[make_pair(x, y)] = i;
			else g[it -> second].push_back(i), g[i].push_back(it -> second);
		}
	}
	findroot(1, 0, m), label[R] = 1, divide(R);
	for(int i = 1; i <= m; i++) cout << label[i] << " ";
	return 0;
}

/*
2022/5/1
start thinking at 14:06

.
.
 POI2004 JAS

 =.= !!!
!!!! .

start coding at 14:27
finish debugging at 15:13
*/