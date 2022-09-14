#include <bits/stdc++.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10, sq = 370;

int v[maxn];
pair <int, pii> z[maxn];
bool used[maxn];
set <int> s[maxn];
int pre[maxn];
vector <int> g[maxn];
ll ans[maxn];
ll tr[maxn];

void change(int pos, int x) {
	for ( ; pos < maxn; pos |= pos + 1) {
		tr[pos] += x;
	}
}

ll go(int pos) {
	ll ans = 0;
	
	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += tr[pos];
	}
	
	return ans;
}

ll get_ans(int l, int r) {
	return go(r) - go(l - 1);
}

int main() {
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		//v[i] = i;
	}
	
	for (int it = 0; it < m; it += sq) {
		memset(used, 0, sizeof used);
		int r = min(m, it + sq);
		
		vector <int> wh;
		
		for (int j = it; j < r; j++) {
			scanf("%d %d %d", &z[j].first, &z[j].second.first, &z[j].second.second);
			//z[j].first = rand() % 2 + 1;
			
			if (z[j].first == 1) {
				//z[j].second.first = rand() % n + 1;
				//z[j].second.second = rand() % n + 1;
				if (!used[v[z[j].second.first]]) {
					wh.push_back(v[z[j].second.first]);
				}
				used[v[z[j].second.first]] = true;
				if (!used[z[j].second.second]) {
					wh.push_back(z[j].second.second);
				}
				used[z[j].second.second] = true;
			} else {
				//z[j].second.first = 1;
				//z[j].second.second = n;
				g[z[j].second.second].push_back(j);
			}
		}
		
		memset(pre, -1, sizeof pre);
		memset(tr, 0, sizeof tr);
		
		for (int i = 1; i <= n; i++) {
			s[i].clear();
		}
		
		for (int i = 1; i <= n; i++) {
			if (used[v[i]]) {
				s[v[i]].insert(i);
			} else {
				if (pre[v[i]] != -1) {
					change(pre[v[i]], i - pre[v[i]]);
				}
				
				pre[v[i]] = i;
			}
			
			for (int j = 0; j < (int)g[i].size(); j++) {
				int num = g[i][j];
				
				ans[num] = get_ans(z[num].second.first, z[num].second.second);
			}
			
			g[i].clear();
		}
		
		for (int i = it; i < r; i++) {
			if (z[i].first == 1) {
				int p = z[i].second.first;
				int x = z[i].second.second;
				s[v[p]].erase(p);
				v[p] = x;
				s[x].insert(p);
			} else {
				int l = z[i].second.first;
				int r = z[i].second.second;
				
				for (int j = 0; j < (int)wh.size(); j++) {
					int x = wh[j];
					auto itt = s[x].lower_bound(l);
					
					if (itt != s[x].end()) {
						int z = -(*itt);
						
						itt = s[x].upper_bound(r);
						
						if (itt != s[x].begin()) {
							itt--;
							
							z += *itt;
							
							if (z >= 0) {
								ans[i] += z;
							}
						}
					}
				}
				
				printf("%lld\n", ans[i]);
			}
		}
	}
	
	return 0;
}