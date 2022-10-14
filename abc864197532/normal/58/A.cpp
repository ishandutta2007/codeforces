#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	string s,t="hello";
	int now=0;
	cin >> s;
	fop (i,0,s.length()) {
		if (s[i]==t[now]) now++;
		if (now==5) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}