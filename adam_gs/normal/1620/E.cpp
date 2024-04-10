#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7;
int T[LIM];
vector<pair<int,int>>V;
vector<int>ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, LIM) T[i]=i;
	int q;
	cin >> q;
	rep(i, q) {
		int t, x, y=-1;
		cin >> t >> x;
		if(t==2) cin >> y;
		V.pb({x, y});
	}
	reverse(all(V));
	for(auto i : V) {
		if(i.nd==-1) ans.pb(T[i.st]);
		else T[i.st]=T[i.nd];
	}
	reverse(all(ans));
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}