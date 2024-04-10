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
	int n;
	cin >> n;
	string T[n];
	rep(i, n) cin >> T[i];
	map<string,int>mp;
	rep(i, n) {
		string p=T[i];
		reverse(all(p));
		if(p==T[i]) {
			cout << "YES\n";
			return;
		}
		if(mp[p]) {
			cout << "YES\n";
			return;
		}
		if(p.size()==2) {
			rep(j, 26) {
				p+=char(j+'a');
				if(mp[p]) {
					cout << "YES\n";
					return;
				}
				p.pop_back();
			}
		}
		mp[T[i]]=1;
	}
	mp.clear();
	for(int i=n-1; i>=0; --i) {
		string p=T[i];
		reverse(all(p));
		if(p.size()==2) {
			rep(j, 26) {
				string x="";
				x+=char(j+'a');
				x+=p;
				if(mp[x]) {
					cout << "YES\n";
					return;
				}
			}
		}
		mp[T[i]]=1;
	}
	cout << "NO\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}