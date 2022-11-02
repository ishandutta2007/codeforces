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
	for(int i = 0; i < q; i++) {
		ll d;
		cin >> d;
		ll c = 1;
		while(c*3 <= d) {
			c *= 3;
		}
		vector<ll> ans;
		ans.pb(0);
		while(c > 0) {
			ans.pb(d/c);
			d %= c;
			c /= 3;
		}
		reverse(ans.begin(), ans.end());
		int t = -1;
		for(int i = 0; i < ans.size(); i++){
			if(ans[i] == 2) t = i;
		}
		if(t != -1) {
			t++;
			while(ans[t] == 1) t++;
			ans[t]++;
			for(int j = 0; j < t; j++) ans[j] = 0;
		}
		ll A = 0, B = 1;
		for(int y = 0; y < ans.size(); y++) {
			A += ans[y] * B;
			B *= 3;
		}
		cout << A << "\n";
	}
 	return 0;
}