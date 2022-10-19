#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>>T(n);
	rep(i, n) {
		cin >> T[i].st;
		T[i].nd=T[i].st;
	}
	while(T.size()>0) {
		sort(all(T));
		if(T.back().st==0) {
			for(auto i : T) cout << i.nd << " ";
			cout << '\n';
			return;
		}
		cout << T.back().nd << " ";
		int x=T.back().st;
		rep(i, T.size()) T[i].st=(T[i].st|x)^x;
		T.pop_back();
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}