#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	int n;
	cin >> n;
	int T[n];
	rep(i,n) cin >> T[i];
	int l=1, m=1;
	rep(i,n-1) {
		if(T[i]>T[i+1]) l=1; else ++l;
		m=max(m, l);
	}
	cout << m;
}