#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7;
int cp[LIM], T[LIM], odl[LIM], odw[LIM], l;
vector<int>pi, podzielne[LIM], V[LIM];
queue<int>q;
void DFS(int x, int o, int p) {
	q.push(x);
	odw[x]=l;
	for(auto i : V[x]) if(i!=o && T[i]%p==0) {
		odl[i]=odl[x]+1;
		DFS(i, x, p);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2; i<LIM; ++i) {
		if(cp[i]) continue;
		pi.pb(i);
		for(int j=2*i; j<LIM; j+=i) cp[j]=1;
	}
	int n, ans=0;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		ans=max(ans, T[i]);
		int x=T[i];
		for(int j=0; pi[j]*pi[j]<=x; ++j) {
			if(x%pi[j]==0) podzielne[pi[j]].pb(i);
			while(x%pi[j]==0) x/=pi[j];
		}
		if(x>1) podzielne[x].pb(i);
	}
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	if(ans==1) {
		cout << "0\n";
		return 0;
	}
	ans=0;
	for(auto i : pi) {
		++l;
		for(auto j : podzielne[i]) if(odw[j]<l) {
			odl[j]=0;
			DFS(j, j, i);
			int ma=-1, x=-1;
			while(!q.empty()) {
				int p=q.front(); q.pop();
				if(odl[p]>ma) {
					ma=odl[p];
					x=p;
				}
			}
			odl[x]=0;
			DFS(x, x, i);
			while(!q.empty()) {
				int p=q.front(); q.pop();
				ans=max(ans, odl[p]);
			}
		}
	}
	cout << ans+1 << '\n';
}