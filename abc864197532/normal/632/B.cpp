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
	lli a[n];
	lli sum=0;
	fop (i,0,n) {
		cin >> a[i];
	}
	cin >> s;
	fop (i,0,n) {
		if (s[i]=='B') sum+=a[i]; 
	}
	lli maxx=sum;
	lli tmp=sum;
	fop (i,0,n) {
		if (s[i]=='A') tmp+=a[i];
		else tmp-=a[i];
		maxx=max(maxx,tmp);
	}
	tmp=sum;
	for (int i=n-1;i>=0;--i) {
		if (s[i]=='A') tmp+=a[i];
		else tmp-=a[i];
		maxx=max(tmp,maxx);
	}
	cout << maxx << endl;
}