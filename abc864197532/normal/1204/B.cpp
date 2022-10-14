#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int n,l,r;
	cin >> n >> l >> r;
	int min=0,max=0;
	fop (i,0,l) {
		min+=(1<<i);
	}
	min+=(n-l);
	fop (i,0,r) {
		max+=(1<<i);
	}
	max+=(n-r)*(1<<(r-1));
	cout << min << ' ' << max << endl;
}