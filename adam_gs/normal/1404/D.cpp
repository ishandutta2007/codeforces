#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7;
vector<pair<ll,ll>>V[LIM];
pair<ll,ll>T[LIM];
ll ans[LIM], odw[LIM], odw2[LIM], n;
void DFS(int x) {
	odw[x]=1;
	for(auto i : V[x]) if(!odw2[i.nd]) {
		odw2[i.nd]=1;
		if(T[i.nd].nd%n==x) ans[i.nd]=1;
		if(!odw[i.st%n]) DFS(i.st%n);
	}
}
int main() {
	cin >> n;
	if(n%2==0) {
		cout << "First" << endl;
		rep(j, 2) rep(i, n) cout << i+1 << " ";
		cout << endl;
		return 0;
	}
	cout << "Second" << endl;
	rep(i, n) T[i]={-1, -1};
	rep(i, 2*n) {
		int a;
		cin >> a; --a;
		if(T[a].st==-1) T[a].st=i+1;
		else T[a].nd=i+1;
	}
	rep(i, n) {
		V[T[i].st%n].pb({T[i].nd%n, i});
		V[T[i].nd%n].pb({T[i].st%n, i});
	}
	rep(i, n) if(!odw[i]) DFS(i);
	ll sum=0;
	rep(i, n) sum+=(ans[i]?T[i].nd:T[i].st);
	if(sum%(2*n)!=0) rep(i, n) ans[i]^=1;
	rep(i, n) cout << (ans[i]?T[i].nd:T[i].st) << " ";
	cout << endl;
}