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
		int n, tmp;
		cin >> n;
		int a[n];
		fop (i,0,n) {
			cin >> tmp;
			a[tmp-1] = i;
		}
		int l = a[0], r = a[0];
		set <int> ans;
		ans.insert(0);
		fop (i,1,n) {
			if (a[i] < l) l = a[i];
			else if (a[i] > r) r = a[i];
			if (r - l == i) ans.insert(i);
		}
		fop (i,0,n) {
			if (ans.count(i)) cout << 1;
			else cout << 0; 
		}
		cout << endl; 
	}
}