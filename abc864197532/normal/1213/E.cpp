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
	string s1,s2;
	cin >> s1 >> s2;
	int x1=s1[0]-'a',x2=s1[1]-'a',y1=s2[0]-'a',y2=s2[1]-'a';
	if (x1==y1 and x2!=y1 and y2!=y1 and x2!=y2) {
		cout << "YES" << endl;
		fop (i,0,2*n) {
			if (i%2==0) {
				cout << char('a'+y2);
			} else {
				cout << char('a'+x2);
			}
		} fop (i,0,n) {
			cout << char('a'+x1);
		}
		cout << endl;
		return 0;
	}
	
	if (x2==y2 and x1!=y2 and y1!=y2 and x1!=y1) {
		cout << "YES" << endl;
		fop (i,0,n) {
			cout << char('a'+x2);
		} fop (i,0,2*n) {
			if (i%2==0) {
				cout << char('a'+y1);
			} else {
				cout << char('a'+x1);
			}
		}
		cout << endl;
		return 0;
	}
	
	if (x1==y2 and x2==y1 and x1!=x2) {
		cout << "YES" << endl;
		fop (i,0,n) cout << char('a'+x1);
		fop (i,0,n) cout << char('a'+3-x1-x2);
		fop (i,0,n) cout << char('a'+x2);
		cout << endl;
		return 0;
	}
	
	int a[3]={0,1,2};
	do {
		if (a[0]==x1 and a[1]==x2) continue;
		if (a[0]==y1 and a[1]==y2) continue;
		if (a[1]==x1 and a[2]==x2) continue;
		if (a[1]==y1 and a[2]==y2) continue;
		if (a[2]==x1 and a[0]==x2) continue;
		if (a[2]==y1 and a[0]==y2) continue;
		cout << "YES" << endl;
		fop (i,0,3*n) {
			if (i%3==0) cout << char('a'+a[0]);
			if (i%3==1) cout << char('a'+a[1]);
			if (i%3==2) cout << char('a'+a[2]);
		}
		cout << endl;
		return 0;
	} while ((next_permutation(a,a+3)));
	cout << "NO" << endl;
}