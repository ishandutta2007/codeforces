#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

bool bigger(string s1,string s2) {
	if (s1+s2<s2+s1) return true;
	return false;
}



int main () {
	int n;
	cin >> n;
	string s[n];
	fop (i,0,n) {
		cin >> s[i];
	}
	sort(s,s+n,bigger);
	fop (i,0,n) {
		cout << s[i];
	}
	cout << endl;
}