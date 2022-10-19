#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int x1, p1, x2, p2;
	cin >> x1 >> p1 >> x2 >> p2;
	int c1=p1, c2=p2;
	for(int i=x1; i; i/=10) ++c1;
	for(int i=x2; i; i/=10) ++c2;
	if(c1<c2) {
		cout << "<\n";
		return;
	}
	if(c1>c2) {
		cout << ">\n";
		return;
	}
	while(p1>p2) {
		x1*=10;
		--p1;
	}
	while(p2>p1) {
		x2*=10;
		--p2;
	}
	if(x1<x2) {
		cout << "<\n";
		return;
	}
	if(x1>x2) {
		cout << ">\n";
		return;
	}
	cout << "=\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}