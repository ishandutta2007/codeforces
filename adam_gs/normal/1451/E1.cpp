#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int kiedy[1<<16], pref, pr[1<<16], T[1<<16];
int main() {
	int n, l1=-1, l2=-1;
	cin >> n;
	rep(i, (1<<16)-1) kiedy[i+1]=-1;
	rep(i, n-1) {
		cout << "XOR " << i+1 << " " << i+2 << endl;
		cin >> pr[i];
		pref^=pr[i];
		if(kiedy[pref]!=-1) {
			l1=kiedy[pref], l2=i+1;
		}
		kiedy[pref]=i+1;
	}
	if(l1!=-1) {
		cout << "OR " << l1+1 << " " << l2+1 << endl;
		cin >> T[l1];
	} else {
		pref=0;
		int l=0;
		while(pref!=n-1) {
			pref^=pr[l];
			++l;
		}
		int p, a, b;
		if(l==1) p=2;
		else p=1;
		cout << "OR 1 " << p+1 << endl;
		cin >> a;
		cout << "OR " << l+1 << " " << p+1 << endl;
		cin >> b;
		a&=b;
		T[p]=a;
		l1=p;
	}
	pref=0;
	for(int i=l1-1; i>=0; --i) {
		pref^=pr[i];
		T[i]=pref^T[l1];
	}
	pref=0;
	for(int i=l1; i<n-1; ++i) {
		pref^=pr[i];
		T[i+1]=pref^T[l1];
	}
	cout << "! ";
	rep(i, n) cout << T[i] << " ";
	cout << endl;
}