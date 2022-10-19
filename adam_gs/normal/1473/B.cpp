#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
int euk(int a, int b) {
	if(a==0) return b;
	return euk(b%a, a);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string a, b, c="", d="";
		cin >> a >> b;
		int p=a.size()*b.size()/euk(a.size(), b.size());
		while(c.size()<p) c+=a;
		while(d.size()<p) d+=b;
		cout << (c==d?c:"-1") << '\n';
	}
}