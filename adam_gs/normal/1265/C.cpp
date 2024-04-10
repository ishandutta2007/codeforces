#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n];
	map<int,int>ile;
	rep(i, n) {
		cin >> T[i];
		++ile[T[i]];
	}
	int g=ile[T[0]], s=0, b=0;
	map<int,int>mp;
	mp[T[0]]=1;
	rep(i, n) {
		if(mp[T[i]]) continue;
		if(g>=s) {
			s+=ile[T[i]];
			mp[T[i]]=1;
		} else if(g+s+b+ile[T[i]]>n/2) break;
		else {
			b+=ile[T[i]];
			mp[T[i]]=1;
		}
	}
	if(g+s+b>n/2 || g>=s || g>=b) {
		g=s=b=0;
	}
	cout << g << " " << s << " " << b << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}