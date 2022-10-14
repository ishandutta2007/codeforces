#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,x,y,maxx=0;
	cin >> n;
	fop (i,0,n) {
		cin >> x >> y;
		maxx=max(maxx,x+y);
	}
	cout << maxx << endl;
}