#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
	int n;
	string x;
	cin >> n >> x;
	char a[n], b[n];
	int zero=0, ile=0;
	rep(i, n) {
		if(x[i]=='1') ++zero;
	}
	if(zero%2) {
		cout << "NO\n";
		return;
	}
	int pierwszy=0, drugi=0, mip=0, mid=0;
	zero/=2;
	rep(i, n) {
		if(x[i]=='1') {
			if(ile<zero) {
				a[i]='(';
				b[i]='(';
				++pierwszy;
				++drugi;
			} else {
				a[i]=')';
				b[i]=')';
				--pierwszy;
				--drugi;
			}
			++ile;
		} else {
			if(pierwszy<=drugi) {
				++pierwszy;
				--drugi;
				a[i]='(';
				b[i]=')';
			} else {
				--pierwszy;
				++drugi;
				a[i]=')';
				b[i]='(';
			}
		}
		mip=min(mip, pierwszy);
		mid=min(mid, drugi);
	}
	if(pierwszy || drugi || mip<0 || mid<0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	rep(i, n) cout << a[i];
	cout << '\n';
	rep(i, n) cout << b[i];
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}