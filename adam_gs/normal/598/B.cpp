#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int m;
	cin >> s >> m;
	while(m--) {
		int l, r, k;
		cin >> l >> r >> k; --l; --r; k%=r-l+1;
		string x="";
		for(int i=l; i<=r; ++i) x+="#";
		rep(i, r-l+1) x[(i+k)%(r-l+1)]=s[i+l];
		rep(i, r-l+1) s[i+l]=x[i];
	}
	cout << s << '\n';
}