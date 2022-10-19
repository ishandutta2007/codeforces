#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
ll dc(string &s, int l, int r, char c) {
	if(l==r) return (s[l]==c?0:1);
	int mid=(l+r)/2;
	int ilea=0, ileb=0;
	for(int i=l; i<=mid; ++i) if(s[i]!=c) ++ilea;
	for(int i=mid+1; i<=r; ++i) if(s[i]!=c) ++ileb;
	return min(ilea+dc(s, mid+1, r, c+1), ileb+dc(s, l, mid, c+1));
}
void solve() {
	int n;
	string s;
	cin >> n >> s;
	cout << dc(s, 0, n-1, 'a') << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}