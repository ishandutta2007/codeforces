#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define lli long long int


int main () {
	int t;
	cin >> t;
	for (int k=0;k<t;++k) {
		int n,m=1000;
		string s;
		cin >> n >> s;
		for (int i=0;i<n;++i) {
			if (s[i]=='8') {
				m=i;
				i=n;
			}
		}
		if (n-m>=11) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}