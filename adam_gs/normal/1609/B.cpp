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
	int n, q;
	string s;
	cin >> n >> q >> s;
	int ans=0;
	string x="abc";
	rep(i, n-2) if(s.substr(i, 3)==x) ++ans;
	while(q--) {
		int a;
		char b;
		cin >> a >> b; --a;
		for(int i=max(a-2, 0); i+2<=min(a+2, n-1); ++i) if(s.substr(i, 3)==x) --ans;
		s[a]=b;
		for(int i=max(a-2, 0); i+2<=min(a+2, n-1); ++i) if(s.substr(i, 3)==x) ++ans;
		cout << ans << '\n';
	}
}