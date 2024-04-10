#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
	int n, s=0, s2=0;
	cin >> n;
	int T[n];
	rep(i,n) {
		cin>>T[i];
		s+=T[i];
	}
	sort(T, T+n);
	int l = 0;
	for(int i = n-1; i >= 0; --i) {
		s2+=T[i];
		++l;
		if(s-s2<s2) break;
	}
	cout << l;
}