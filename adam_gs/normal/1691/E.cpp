#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7, INF=1e9+7;
int F[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	F[fnd(b)]=fnd(a);
	return true;
}
void solve() {
	vector<pair<pair<int,int>,int>>S, V;
	int n;
	cin >> n;
	rep(i, n) {
		F[i]=i;
		int c, l, r;
		cin >> c >> l >> r;
		if(!c) S.pb({{l, r}, i});
		else V.pb({{r, l}, i});
	}
	sort(all(V));
	sort(all(S));
	int ans=n, l=0;
	priority_queue<pair<int,int>>q;
	for(auto i : V) {
		while(l<S.size() && S[l].st.st<=i.st.st) {
			q.push({S[l].st.nd, S[l].nd});
			++l;
		}
		if(q.empty()) continue;
		if(q.top().st>=i.st.nd) {
			if(uni(i.nd, q.top().nd)) --ans;
			int a=q.top().st, b=q.top().nd; q.pop();
			while(!q.empty()) {
				if(q.top().st<i.st.nd) break;
				if(uni(i.nd, q.top().nd)) --ans;
				q.pop();
			}
			q.push({a, b});
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}