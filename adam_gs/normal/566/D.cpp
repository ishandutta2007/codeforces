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
int F[LIM], mi[LIM], ma[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
int fnd2(int x) {
	if(ma[x]==x) return x;
	return ma[x]=fnd2(ma[x]);
}
void uni(int a, int b) {
	F[fnd(b)]=fnd(a);
}
void uni2(int a, int b) {
	if(fnd2(a)==fnd2(b)) return;
	a=fnd2(a);
	b=fnd2(b);
	uni(a, b);
	mi[b]=mi[a];
	ma[a]=b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	rep(i, n) F[i]=mi[i]=ma[i]=i;
	while(q--) {
		int t, a, b;
		cin >> t >> a >> b; --a; --b;
		if(t==1) uni(a, b);
		else if(t==3) cout << (fnd(a)==fnd(b)?"YES":"NO") << '\n';
		else while(fnd2(a)!=fnd2(b)) uni2(ma[a], ma[a]+1);
	}
}