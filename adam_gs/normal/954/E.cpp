#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ld EPS=0.0000001;
const int LIM=2e5+7;
pair<ld,ld>T[LIM];
ld ile[LIM], k;
int n;
bool f(ld x) {
	ld p=x, akt=0, akt2=0;
	rep(i, n) {
		akt+=T[i].st*min(T[i].nd, p);
		p-=min(T[i].nd, p);
	}
	p=x;
	for(int i=n-1; i>=0; --i) {
		akt2+=T[i].st*min(T[i].nd, p);
		p-=min(T[i].nd, p);
	}
	return akt<=x*k && akt2>=x*k;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ld po=0, ko=0;
	cin >> n >> k;
	rep(i, n) {
		int x;
		cin >> x;
		T[i].nd=x;
		ko+=T[i].nd;
	}
	rep(i, n) {
		int x;
		cin >> x;
		T[i].st=x;
	}
	sort(T, T+n);
	if(T[0].st>k || T[n-1].st<k) {
		cout << 0 << '\n';
		return 0;
	}
	while(po+EPS<ko) {
		ld sr=(po+ko)/2;
		if(f(sr)) po=sr+EPS; else ko=sr-EPS;
	}
	cout << fixed << setprecision(6) << po << '\n';
}