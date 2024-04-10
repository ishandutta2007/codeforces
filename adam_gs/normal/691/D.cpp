#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
int T[LIM], F[LIM], li[LIM];
vector<int>V[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
	if(fnd(a)==fnd(b)) return;
	F[fnd(b)]=fnd(a);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i];
		F[i]=i;
	}
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		uni(a, b);
	}
	rep(i, n) V[fnd(i)].pb(T[i]);
	rep(i, n) {
		sort(all(V[i]));
		reverse(all(V[i]));
	}
	rep(i, n) {
		cout << V[fnd(i)][li[fnd(i)]] << " ";
		++li[fnd(i)];
	}
	cout << '\n';
}