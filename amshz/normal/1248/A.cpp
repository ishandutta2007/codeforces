# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

# define push_back pb;

const int xn = 1e5+10;
ll p[xn], q[xn];

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> p[i];
		int m;
		cin >> m;
		for (int i=0; i<m; i++) cin >> q[i];
		long long ans = 0;
		ll t1 = 0, t2 = 0;
		for (int i=0; i<n; i++){
			if (p[i]%2 == 0) t1++;
			else t2++;
		}
		ll r2 = 0, r1 = 0;
		for (int i=0; i<m; i++){
			if (q[i]%2 == 0) r1++;
			else r2++;
		}
		ans = r1*t1+r2*t2;
		cout <<   ans << endl;
	}
}