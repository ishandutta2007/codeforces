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
	string a, b;
	cin >> a >> b;
	int ktora[26];
	rep(i, 26) ktora[a[i]-'a']=i;
	int ans=0;
	rep(i, b.size()-1) ans+=abs(ktora[b[i]-'a']-ktora[b[i+1]-'a']);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}