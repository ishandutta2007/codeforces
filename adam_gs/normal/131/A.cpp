#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(a, b) for(int a = 0; a < (b); ++a)
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x;
	cin >> x;
	bool t = true;
	rep(i, x.size()-1) {
		if (x[i+1]==tolower(x[i+1])) t=false;
	}
	if(t==true) {
		rep(i, x.size()) {
			if(x[i]<='z' && x[i]>='a') {
				x[i]=toupper(x[i]); 
			} else {
				x[i]=tolower(x[i]);
			}
			cout << x[i];
		}
	} else {
		cout << x;
	}
}