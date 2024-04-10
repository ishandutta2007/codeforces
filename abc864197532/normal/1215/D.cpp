#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int n,a=0,b=0,n1=0,n2=0;
	string s;
	cin >> n >> s;
	fop (i,0,n/2) {
		if (s[i]=='?') n1++;
		else a+=(s[i]-'0');
	}
	fop (i,n/2,n) {
		if (s[i]=='?') n2++;
		else b+=(s[i]-'0');
	}
	if (n1>n2) {
		swap(n1,n2);
		swap(a,b);
	}
	if (a-b==9*(n2-n1)/2) {
		cout << "Bicarp" << endl;
	} else {
		cout << "Monocarp" << endl;
	}
}