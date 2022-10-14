#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	string a;
	int n,c=0,s=0,t=0;
	cin >> a >> n;
	fop (i,1,a.length()) {
		if (a[i]=='?') c++;
		if (a[i]=='*') s++;
	}
	t=a.length()-n-c-s;
	if (t>c+s) {
		cout << "Impossible" << endl;
	} else if (t<=c+s and t>=0) {
		fop (i,0,a.length()-1) {
			if (a[i]=='*' or a[i]=='?') {
				continue;
			} else if (t==0) {
				cout << a[i];
			} else if (a[i+1]=='*' or a[i+1]=='?') {
				t--;
			} else {
				cout << a[i];
			}
		}
		if (a[a.length()-1]!='?' and a[a.length()-1]!='*') cout << a[a.length()-1];
		cout << endl;
	} else if (t<0 and s>0) {
		fop (i,0,a.length()-1) {
			if (a[i]!='?' and a[i]!='*') cout << a[i];
			if (t!=0 and a[i+1]=='*') {
				fop (j,t,0) {
					cout << a[i];
				}
				t=0;
			}
		}
		if (a[a.length()-1]!='?' and a[a.length()-1]!='*') cout << a[a.length()-1];
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
	
}