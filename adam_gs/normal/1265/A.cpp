#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	string x;
	cin >> x;
	if(x.size()==1) {
		if(x[0]=='?') x[0]='a';
		cout << x << '\n';
		return;
	}
	rep(i, x.size()) if(x[i]=='?') {
		if(!i) {
			if(x[i+1]=='a') x[i]='b';
			else x[i]='a';
		} else if(i==x.size()-1) {
			if(x[i-1]=='a') x[i]='b';
			else x[i]='a';
		} else {
			if(x[i-1]=='a' || x[i+1]=='a') {
				if(x[i-1]=='b' || x[i+1]=='b') x[i]='c';
				else x[i]='b';
			} else x[i]='a';
		}
	}
	rep(i, x.size()-1) if(x[i]==x[i+1]) {
		cout << -1 << '\n';
		return;
	}
	cout << x << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}