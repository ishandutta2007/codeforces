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
	int n;
	cin >> n;
	int a[300000];
	fop (i,0,n) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int p[300000], all[300000];
	fop (i,0,m) {
		all[i] = 0;
		int t;
		cin >> t;
		if (t == 1) {
			int b,c;
			cin >> b >> c;
			a[b-1] = c;
			p[b-1] = i;
		} else {
                        cin >> all[i];
		}
	}
	fop (i,m,1) all[i-1] = max(all[i], all[i-1]);
	fop (i,0,n) {
		cout << max(a[i], all[p[i]]) << " \n"[i == n-1];
	}
}