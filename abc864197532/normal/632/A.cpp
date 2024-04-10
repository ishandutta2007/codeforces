#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	long long int n,p,now=0,kk=0;
	string s;
	cin >> n >> p;
	int a[n];
	fop (i,0,n) {
		cin >> s;
		if (s=="half") a[i]=0;
		else a[i]=1; 
	}
	for (int i=n-1;i>=0;--i) {
		if (a[i]) {
			now=2*now+1;
			kk+=now;
		} else {
			now*=2;
			kk+=now;
		}
	}
	cout << kk*p/2 << endl;
}