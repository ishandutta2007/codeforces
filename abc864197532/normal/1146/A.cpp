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
	int k=s.length(),n=0;
	fop (i,0,k) {
		if (s[i]=='a') n++;
	}
	cout << min(2*n-1,k) << endl;
}