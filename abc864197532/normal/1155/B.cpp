#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,e=0;
	string s;
	cin >> n >> s;
	fop (i,0,n-10) {
		if (s[i]=='8') {
			e++;
		}
	}
	if (e>(n-11)/2) cout << "YES" << endl;
	else cout << "NO" << endl;
}