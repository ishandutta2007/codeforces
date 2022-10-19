#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
const int LIM=15e4+7, MAXA=2e6+7;
int T[LIM], F[MAXA], jest[MAXA], cp[MAXA], wjakiej[MAXA];
vector<int>pierwsze[MAXA];
vector<int>V[LIM];
map<pair<int,int>,int>krawedz;
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
	int n, q;
	cin >> n >> q;
	rep(i, MAXA) {
		F[i]=i;
		wjakiej[i]=-1;
	}
	rep(i, n) {
		cin >> T[i];
		jest[T[i]]=1;
	}
	for(int i=2; i<MAXA; ++i) {
		for(int j=i; j<MAXA; j+=i) {
			if(jest[j]) uni(i, j);
		}
	}
	for(int i=2; i<MAXA; ++i) {
		if(cp[i]) continue;
		for(int j=i; j<MAXA; j+=i) {
			pierwsze[j].pb(i);
			cp[j]=1;
		}
	}
	for(int i=2; i<MAXA; ++i) {
		if(!jest[i]) continue;
		for(auto j : pierwsze[i]) wjakiej[j]=fnd(i);
	}
	rep(i, n) {
		for(auto j : pierwsze[T[i]+1]) {
			if(wjakiej[j]!=-1) {
				krawedz[{fnd(T[i]), wjakiej[j]}]=1;
				krawedz[{wjakiej[j], fnd(T[i])}]=1;
			}
		}
		for(auto j : pierwsze[T[i]+1]) {
			for(auto l : pierwsze[T[i]+1]) {
				krawedz[{fnd(l), fnd(j)}]=1;
				krawedz[{fnd(j), fnd(l)}]=1;
			}
		}
	}
	while(q--) {
		int a, b;
		cin >> a >> b; --a; --b;
		if(fnd(T[a])==fnd(T[b])) {
			cout << 0 << '\n';
		} else if(krawedz[{fnd(T[a]), fnd(T[b])}]) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}