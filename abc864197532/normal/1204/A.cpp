#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	string s;
	cin >> s;
	int is=1;
	fop (i,1,s.length()) {
		if (!is) break;
		if (s[i]=='1') is=0;
	} 
	if (s.length()%2==1) cout << (s.length()+1)/2-is << endl;
	else cout << s.length()/2 << endl;
}