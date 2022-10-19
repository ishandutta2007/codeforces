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
	int x, T[3];
	cin >> x; --x;
	rep(i, 3) {
		cin >> T[i]; --T[i];
	}
	if(T[x]==-1) {
		cout << "NO\n";
		return;
	}
	cout << (T[T[x]]==-1?"NO":"YES") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}