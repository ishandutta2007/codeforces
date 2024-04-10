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
		int n;
		cin >> n;
		vector <int> a(n);
		fop (i,0,n) cin >> a[i];
		for (int i = 0, j = 1; i < n && j <= n;) {
			int k = i;
			while (a[i] != j and i < n) i++;
			if (i == n) i = k, j++;
			else if (i == k) {
				i++;
				j++; 
			} else {
				a.erase(a.begin()+i);
				a.insert(a.begin()+k,j);
				j++;
			}
		}
		fop (i,0,n) cout << a[i] << " \n" [i == n - 1];
	}
}