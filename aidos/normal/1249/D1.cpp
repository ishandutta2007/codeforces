#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n, k;
int a[200200];
int l[200200];
int r[200200];
int c[200200];
int p[200200];
vector<int> I[200200], O[200200];
int u[200200];
set< pair<int, int> > S;
int main () {
	cin >> n >> k;
	int M = 0;
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		M = max(M,r[i]);
		I[l[i]].pb(i);
		O[r[i]].pb(i);
	}
	int ans = 0;
	for(int i = 1; i <= M; i++) {
		for(int j = 0; j < I[i].size(); j++) {
			int ind = I[i][j];
			S.insert(make_pair(r[ind], ind));
		}
		while(S.size() > k) {
			pair<int, int> d = *(--S.end());
			ans++;
			u[d.s] = 1;
			S.erase(d);
		}
		for(int j = 0; j < O[i].size(); j++){
			int ind = O[i][j];
			S.erase(make_pair(r[ind], ind));
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++) {
		if(u[i]) cout << i + 1 << " ";
	}
 	return 0;
}