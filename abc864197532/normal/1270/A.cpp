#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,a1,a2,tmp;
		cin >> n >> a1 >> a2;
		bool is = true;
		fop (i,0,a1) {
			cin >> tmp;
			if (tmp == n) is = true;
		} fop (i,0,a2) {
			cin >> tmp;
			if (tmp == n) is = false;
		}
		if (is) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
}