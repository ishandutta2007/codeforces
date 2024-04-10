#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,m,tmp;
		cin >> n;
		int a[n],b[n];
		fop (i,0,n) {
			cin >> a[i];
		}
		cin >> m;
		vector <int> p(n,0); // p[i] = i+1 
		int p_size = 0;
		fop (i,0,m) {
			int a1,a2;
			cin >> a1 >> a2; 
			p_size = max(p_size, a2);
			p[a2-1] = max(p[a2-1], a1);
		}
		fop (i,n-1,0) p[i] = max(p[i], p[i+1]);
		p.resize(p_size);
		reverse(p.begin(), p.end());
		int ans = 0, maxx = 0, i = 0, j = 1;
		bool is = false;
		while (i < n and j <= n) {
		    maxx = max(maxx, a[j-1]);
		    if (maxx > p[p_size-1]) {
		        is = true;
		        break;
		    }
		    if (p_size - (lower_bound(p.begin(), p.end(), maxx) - p.begin()) < j - i) {
		        i = j - 1;
		        ans++;
		        maxx = 0;
		    } else {
		        j++;
		    }
		}
		if (!is) cout << ans + 1 << endl;
		else cout << -1 << endl;
	}
}