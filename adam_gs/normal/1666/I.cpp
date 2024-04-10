#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int sc(int a, int b) {
	cout << "SCAN " << a << " " << b << endl;
	int x;
	cin >> x;
	return x;
}
int dg(int a, int b) {
	cout << "DIG " << a << " " << b << endl;
	int x;
	cin >> x;
	return x;
}
void solve() {
	int n, m;
	cin >> n >> m;
	int a=sc(1, 1), b=sc(n, 1);
	int sumc=(a+b)/2-n+3, sumr=(a-b)/2+n+1;
	int rozr=sc(sumr/2, 1), rozc=sc(1, sumc/2);
	rozr-=sumc-2; rozc-=sumr-2;
	int r1=(sumr+rozr)/2, c1=(sumc+rozc)/2;
	int r2=sumr-r1, c2=sumc-c1;
	if(dg(r1, c1)) dg(r2, c2);
	else {
		dg(r1, c2);
		dg(r2, c1);
	}
}
int main() {
	int _;
	cin >> _;
	while(_--) solve();
}