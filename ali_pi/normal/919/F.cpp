#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 501;

vector < vector < int > > pos;
map < vector < int >, int > go;

vector < int > G [ maxn * maxn ];

int dp[maxn * maxn];
int impl[maxn * maxn];
bool exs[maxn * maxn];

inline int singlize(int x, int y) {
	return (x * maxn + y);
}

void dfs(int x) {
	exs[x] = false;
	for (int y : G[x]) {
		if (!exs[y]) continue;

		if (dp[x] == 1) {
			dp[y] = 0; dfs(y);
		} else if (dp[x] == 0) {
			impl[y]--; 
			if (impl[y] == 0) {
				dp[y] = 1; dfs(y);
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(false); cin.tie(0);

	vector < int > v;

	for (int i0 = 0; i0 <= 8; i0++) {
		for (int i1 = 0; i1 <= 8; i1++) {
			for (int i2 = 0; i2 <= 8; i2++) {
				for (int i3 = 0; i3 <= 8; i3++) {
					for (int i4 = 0; i4 <= 8; i4++) {
						if (i0 + i1 + i2 + i3 + i4 != 8) continue;
						
						v.clear(); v.pb(i0); v.pb(i1); v.pb(i2); v.pb(i3); v.pb(i4);
						pos.pb(v);

						go[v] = pos.size() - 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < maxn * maxn; i++) {
		dp[i] = -1; exs[i] = true; impl[i] = 0;
	}

	vector < int > win(5); win[0] = 8;				
	int widx = go[win];
	
	for (int i = 0; i < pos.size(); i++) {
		for (int j = 0; j < pos.size(); j++) {
			int f = singlize(i, j);
			
			vector < int > a = pos[i], b = pos[j];	

			for (int p = 1; p < 5; p++) {
				for (int q = 1; q < 5; q++) {
					if (a[p] == 0 || b[q] == 0) continue;
					int r = (p + q)%5;

					a[r]++; a[p]--;
					
					int t = singlize(j, go[a]);
					G[t].pb(f);                      

					impl[f]++;

					a[r]--; a[p]++;
				}
			}
		}
	}
					
	for (int i = 0; i < pos.size(); i++) {
		if (i == widx) continue;
		int f = singlize(i, widx);
		dp[f] = 1;
		dfs(f);
		f = singlize(widx, i);
		dp[f] = 0;
		dfs(f);
	}

	int t; cin >> t;
	while (t--) {
		int p; cin >> p;
		vector < int > X(5), Y(5);
		for (int i = 0; i < 8; i++) {
			int x; cin >> x; X[x]++;
		}
		for (int i = 0; i < 8; i++) {
			int x; cin >> x; Y[x]++;
		}

		int a = go[X], b = go[Y];
		int z = (p == 0) ? dp[ singlize(a, b) ] : dp[ singlize(b, a) ];

		if (z == -1) {
			cout << "Deal" << endl; continue;
		}
		p ^= z;

		cout << ((p == 0) ? "Alice" : "Bob") << endl;
	}

}