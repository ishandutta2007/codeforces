#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	fop (i,1,s.length()) {
		if (s[i]<s[i-1]) {
			cout << "YES" << endl;
			cout << i << ' ' << i+1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0; 
}