#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int T[LIM], n, k;
bool f(int x) {
	int l1=0;
	rep(i, n) {
		if(l1%2==0) {
			++l1;
		} else if(l1%2==1 && T[i]<=x) {
			++l1;
		}
	}
	int l2=0;
	rep(i, n) {
		if(l2%2==1) {
			++l2;
		} else if(l2%2==0 && T[i]<=x) {
			++l2;
		}
	}
	return max(l1, l2)>=k;
}
void solve() {
	cin >> n >> k;
	rep(i, n) cin >> T[i];
	int p=1, k=1000000000;
	while(p<k) {
		int sr=(p+k)/2;
		if(f(sr)) k=sr; else p=sr+1;
	}
	cout << p << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}