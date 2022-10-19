#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define M_PI 3.14159265358979323846
void solve() {
	int n;
	cin >> n;
	ld x=n;
	ld a=2*(1-cos(M_PI/x));
	a=1/a;
	ld h=sqrt(a-(ld)1/4);
	h*=2;
	cout << fixed << setprecision(6) << h << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}