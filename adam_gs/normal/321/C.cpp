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
vector<int>V[LIM];
int zdj[LIM], ile[LIM], rozmiar, ma[LIM], ans[LIM];
queue<int>q;
void DFS(int x, int o) {
	q.push(x);
	++rozmiar;
	ile[x]=1;
	ma[x]=0;
	for(auto i : V[x]) if(!zdj[i] && i!=o) DFS(i, x);
	for(auto i : V[x]) if(!zdj[i] && i!=o) {
		ma[x]=max(ma[x], ile[i]);
		ile[x]+=ile[i];
	}
}
int znajdz(int x) {
	rozmiar=0;
	DFS(x, -1);
	int centroid;
	while(!q.empty()) {
		int p=q.front(); q.pop();
		if(p!=x) ma[p]=max(ma[p], rozmiar-ile[p]);
		if(ma[p]<=rozmiar/2) centroid=p;
	}
	return centroid;
}
void cd(int x, int poz) {
	int p=znajdz(x);
	ans[p]=poz;
	zdj[p]=1;
	for(auto i : V[p]) if(!zdj[i]) cd(i, poz+1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	cd(0, 0);
	rep(i, n) cout << char('A'+ans[i]) << " ";
}