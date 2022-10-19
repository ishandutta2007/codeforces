#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e6+7, LG=20;
int nxt[LIM][LG], sum[LIM], cl[LIM];
const int INF=1e9+7;
void solve() {
	string x;
	int m;
	cin >> x >> m;
	int n=x.size();
	rep(i, n) {
		sum[i+1]=sum[i];
		cl[i+1]=cl[i];
		if(x[i]==')') {
			--sum[i+1];
			++cl[i+1];
		} else ++sum[i+1];
	}
	stack<pair<int,int>>q;
	q.push({-INF, n+1});
	nxt[n+1][0]=n+1;
	for(int i=n; i>=0; --i) {
		while(q.top().st>=sum[i]) q.pop();
		nxt[i][0]=q.top().nd;
		q.push({sum[i], i});
	}
	for(int j=1; j<LG; ++j) {
		rep(i, n+2) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	}
	while(m--) {
		int l, r;
		cin >> l >> r; --l;
		int ans=0, p=cl[r]-cl[l];
		for(int i=LG-1; i>=0; --i) if(nxt[l][i]<=r) {
			l=nxt[l][i];
			ans+=1<<i;
		}
		p-=ans;
		cout << p*2 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}