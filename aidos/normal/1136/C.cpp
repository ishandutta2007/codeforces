#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 1e4 + 100;
int n, m;
int T;
vector<int> a[maxn], b[maxn];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			a[i+j].pb(x);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			b[i+j].pb(x);
		}
	}

	for(int i = 0; i < maxn; i++) {
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
		if(a[i] != b[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";


}