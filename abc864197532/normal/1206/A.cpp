#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
int a[100],b[100],n,m;


int find (int k) {
	fop (i,0,n) {
		if (k==a[i]) return true;
	}
	fop (i,0,m) {
		if (k==b[i]) return true;
	}
	return false;
}
 
 
int main () {
	int N=100000;
	int tmp[N];
	fop (i,0,N) {
		fop (j,0,N) {
			tmp[i]=j;
		}
	}
	cin >> n;
	fop (i,0,n) cin >> a[i];
	cin >> m;
	fop (i,0,m) cin >> b[i];
	fop (i,0,n) {
		fop (j,0,m) {
			if (!find(a[i]+b[j])) {
				cout << a[i] << ' ' << b[j] << endl;
				return 0;
			}
		}
	}
}