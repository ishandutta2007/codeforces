#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int pytaj(int a, int b, int c, int d) {
	cout << "? " << b-a+1 << " " << d-c+1 << endl;
	while(a<=b) {
		cout << a << " ";
		++a;
	}
	cout << endl;
	while(c<=d) {
		cout << c << " ";
		++c;
	}
	cout << endl;
	string x;
	cin >> x;
	if(x[0]=='F') return -1;
	if(x[0]=='E') return 0;
	return 1;
}
void znajdz(int l, int r) {
	if(l==r) {
		cout << "! " << l << endl;
		return;
	}
	int mid=(l+r)/2;
	if(pytaj(1, mid-l+1, l, mid)==0) znajdz(mid+1, r);
	else znajdz(l, mid);
}
void solve() {
	int n, k;
	cin >> n >> k;
	rep(i, 25) {
		int a=rand()%(n-1)+2;
		if(pytaj(1, 1, a, a)==1) {
			cout << "! 1" << endl;
			return;
		}
	}
	int akt=1;
	while(2*akt<=n) {
		if(pytaj(1, akt, akt+1, 2*akt)==0) akt*=2;
		else break;
	}
	znajdz(akt+1, min(2*akt, n));
}
int main() {
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int _;
	cin >> _;
	while(_--) solve();
}