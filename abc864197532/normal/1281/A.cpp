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
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		if (s[n-1] == 'o') {
			cout << "FILIPINO";
		} else if (s[n-1] == 'u') {
			cout << "JAPANESE";
		} else {
			cout << "KOREAN";
		} 
		cout << endl;
	}
}