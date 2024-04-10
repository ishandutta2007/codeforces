#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int F[LIM], mi[LIM];
pair<pair<int,int>,int>T[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	mi[fnd(a)]=min(mi[fnd(a)], mi[fnd(b)]);
	F[fnd(b)]=fnd(a);
	return true;
}
void solve() {
	int n, k;
	cin >> n >> k;
	rep(i, n) {
		cin >> T[i].st.st >> T[i].st.nd >> mi[i];
		T[i].nd=i;
		F[i]=i;
	}
	rep(p, 2) {
		sort(T, T+n);
		rep(i, n-1) {
			if(T[i].st.st==T[i+1].st.st && T[i+1].st.nd-T[i].st.nd<=k) {
				uni(T[i].nd, T[i+1].nd);
			}
		}
		rep(i, n) swap(T[i].st.st, T[i].st.nd);
	}
	vector<int>V;
	rep(i, n) if(fnd(i)==i) V.pb(mi[i]);
	sort(all(V));
	reverse(all(V));
	int ans=0;
	rep(i, V.size()-1) {
		if(i>=V[i+1]) break;
		++ans;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}