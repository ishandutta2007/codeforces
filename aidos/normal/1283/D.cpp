#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
const int inf = (1<<30);
int n;
int m;
set<pair<int, int>> S;
set<int> D;
int main () {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		S.insert(mp(0, x));
		D.insert(x);
	}
	std::vector<int> ans;
	ll cost = 0;
	for(int i = 1; i <= n+m; i++) {
		pair<int, int> t = *S.begin();
		S.erase(t);
		if(t.f > 0) {
			ans.pb(t.s);
			cost += t.f;
		}
		if(D.count(t.s-1) == 0) {
			pair<int, int> dd = mp(t.f + 1 ,t.s - 1);
			S.insert(dd);
			D.insert(t.s-1);
		}
		if(D.count(t.s+1) == 0) {
			pair<int, int> dd = mp(t.f + 1 ,t.s + 1);
			S.insert(dd);
			D.insert(t.s+1);
		}
	}
	cout << cost << "\n";
	for(int i = 0; i < m; i++)
		cout << ans[i] << " ";
 	return 0;
}