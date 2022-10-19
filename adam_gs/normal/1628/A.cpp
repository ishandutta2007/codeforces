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
	int T[n];
	rep(i, n) cin >> T[i];
	map<int,int>mp;
	rep(i, n+1) mp[i]=-1;
	rep(i, n) mp[T[i]]=i;
	int ile[n+1];
	rep(i, n+1) ile[i]=0;
	vector<int>V;
	int akt=0, p=0;
	rep(i, n) {
		if(mp[akt]<i && i) {
			V.pb(akt);
			while(p<i) {
				--ile[T[p]];
				++p;
			}
			akt=0;
		}
		++ile[T[i]];
		while(ile[akt]) ++akt;
	}
	V.pb(akt);
	cout << V.size() << '\n';
	for(auto i : V) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}