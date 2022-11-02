#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n;
int a[200200];
int u[200200];
int ans[200200];

int main () {
	int q;
	cin>> q;
	for(int i=0; i < q; i++){
		cin >> n;
		for(int j = 0; j < n; j++) {
			cin >> a[j];
			u[j] = 0;
			a[j]--;
		}
		for(int j = 0; j < n ; j++) {
			int v = j;
			if(u[v]) continue;
			vector<int> cur;
			while(!u[v]) {
				cur.pb(v);
				u[v] = 1;
				v = a[v];
			}
			for(int t = 0; t < cur.size(); t++) {
				ans[cur[t]] = cur.size();
			}
		}
		for(int j = 0; j < n; j++) {
			if(j) cout << " ";
			cout << ans[j];
		}
		cout << "\n";
	}
 	return 0;
}