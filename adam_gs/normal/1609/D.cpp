#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int F[LIM], ile[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	ile[fnd(a)]+=ile[fnd(b)];
	F[fnd(b)]=fnd(a);
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, d;
	cin >> n >> d;
	rep(i, n) {
		F[i]=i;
		ile[i]=1;
	}
	int x=1;
	rep(i, d) {
		int a, b;
		cin >> a >> b; --a; --b;
		if(!uni(a, b)) ++x;
		vector<int>V;
		rep(j, n) if(fnd(j)==j) V.pb(ile[j]);
		sort(all(V));
		reverse(all(V));
		int ans=0;
		rep(j, x) ans+=V[j];
		cout << ans-1 << '\n';
	}
}