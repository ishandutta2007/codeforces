#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
pair< pii, pii > a[100100];
int u[100100];
int n;
int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].f.f >> a[i].f.s >> a[i].s.f;
		a[i].s.s = i+1;
	}
	sort(a, a + n);
	int L = -1;
	vector< pair<int, int> > ans;
	for(int i = 0; i + 1< n; i++) {
		if(u[i]) continue;
		if(a[i].f == a[i+1].f) {
			u[i] = 1;
			u[i+1] = 1;
			ans.pb(make_pair(a[i].s.s, a[i+1].s.s));
		}
	}
	for(int i = 0; i < n; ) {
		int j = i;
		int D = -1;
		while(i < n && a[i].f.f == a[j].f.f) {
			if(!u[i]) {
				if(D == -1) {
					D = a[i].s.s;
				}else{
					ans.pb(make_pair(a[i].s.s, D));
					D = -1;
				}
			}
			i++;
		}
		if(D != -1) {
			if(L!=-1) {
				ans.pb(make_pair(D, L));
				L = -1;
			}else {
				L = D;
			}
		}
	}
	for(int i = 0; i < ans.size(); i++) cout << ans[i].f << " " << ans[i].s << "\n";
 	return 0;
}