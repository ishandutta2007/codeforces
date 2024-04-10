#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7, INF=1e9+7;
int T[LIM], F[LIM], odw[LIM], ans[LIM], ile, mi, jaki, jaki2;
map<int,int>mp;
vector<int>spojne[LIM];
vector<pair<int,int>>V[LIM];
set<int>S;
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
	if(fnd(a)==fnd(b)) return;
	F[fnd(b)]=fnd(a);
	--ile;
}
void akt(int a, int b, int c) {
	if(abs(a-b)<mi) {
		mi=abs(a-b);
		jaki=mp[b];
		jaki2=c;
	}
}
void DFS(int x, int v) {
	odw[x]=1;
	ans[x]=v;
	for(auto i : V[x]) if(!odw[i.st]) DFS(i.st, max(v, i.nd));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q, s, d;
	cin >> n >> q >> s >> d; --s;
	rep(i, n) {
		cin >> T[i];
		mp[T[i]]=i;
		F[i]=i;
		S.insert(T[i]);
	}
	ile=n;
	while(ile>1) {
		rep(i, n) spojne[i].clear();
		rep(i, n) spojne[fnd(i)].pb(i);
		vector<pair<int,pair<int,int>>>nowe;
		rep(i, n) {
			for(auto j : spojne[i]) S.erase(T[j]);
			mi=INF; jaki=-1;
			for(auto j : spojne[i]) {
				auto it=S.lower_bound(T[j]+d);
				int p;
				if(it!=S.end()) {
					p=*it;
					akt(T[j]+d, p, j);
				}
				if(it!=S.begin()) {
					--it;
					p=*it;
					akt(T[j]+d, p, j);
				}
				it=S.lower_bound(T[j]-d);
				if(it!=S.end()) {
					p=*it;
					akt(T[j]-d, p, j);
				}
				if(it!=S.begin()) {
					--it;
					p=*it;
					akt(T[j]-d, p, j);
				}
			}
			if(jaki!=-1) nowe.pb({mi, {jaki, jaki2}});
			for(auto j : spojne[i]) S.insert(T[j]);
		}
		sort(all(nowe));
		for(auto i : nowe) if(fnd(i.nd.st)!=fnd(i.nd.nd)) {
			uni(i.nd.st, i.nd.nd);
			V[i.nd.st].pb({i.nd.nd, i.st});
			V[i.nd.nd].pb({i.nd.st, i.st});
		}
	}
	DFS(s, 0);
	while(q--) {
		int i, k;
		cin >> i >> k; --i;
		cout << (ans[i]<=k?"Yes":"No") << '\n';
	}
}