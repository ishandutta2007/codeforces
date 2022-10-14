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
		string a[n];
		fop (i,0,n) {
			cin >> a[i];
		}
		int count = 0;
		fop (i,0,n) {
			bool is = false, iss = true;
			fop (j,0,n) {
				if (a[j] == a[i] and i != j) is = true;
			}
			if (!is) continue;
			count++;
			char c = '0';
			while (true) {
				a[i][0] = c;
				fop (j,0,n) {
					if (a[j] == a[i] and i != j) iss = false;
				}
				if (iss) break;
				iss = true;
				c++;
			}
		}
		cout << count << endl;
		fop (i,0,n) cout << a[i] << endl;
	}
}