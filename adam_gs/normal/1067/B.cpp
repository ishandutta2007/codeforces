#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
int odl[LIM], lst[LIM];
vector<int>V[LIM];
void DFS(int x, int o) {
	for(auto i : V[x]) if(i!=o) {
		odl[i]=odl[x]+1;
		lst[i]=x;
		DFS(i, x);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	if(n<=3) {
		cout << "No\n";
		return 0;
	}
	DFS(0, 0);
	int ma=-1, akt=-1;
	rep(i, n) if(ma<odl[i]) {
		ma=odl[i];
		akt=i;
	}
	odl[akt]=0;
	lst[akt]=akt;
	DFS(akt, akt);
	ma=-1;
	rep(i, n) if(ma<odl[i]) {
		ma=odl[i];
		akt=i;
	}
	vector<int>srednica;
	while(lst[akt]!=akt) {
		srednica.pb(akt);
		akt=lst[akt];
	}
	srednica.pb(akt);
	if(srednica.size()!=2*k+1) {
		cout << "No\n";
		return 0;
	}
	int jaki=-1;
	rep(i, n) if(V[i].size()==3) {
		if(jaki!=-1) {
			cout << "No\n";
			return 0;
		}
		jaki=i;
	}
	if(jaki!=-1 && jaki!=srednica[srednica.size()/2]) {
		cout << "No\n";
		return 0;
	}
	jaki=srednica[srednica.size()/2];
	odl[jaki]=0;
	DFS(jaki, jaki);
	rep(i, n) if(V[i].size()==1 && odl[i]!=k || V[i].size()==2) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
}