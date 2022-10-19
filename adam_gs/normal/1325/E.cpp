#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7, INF=1e9+7;
int jaka[LIM], ile[LIM], T[LIM], odl[LIM];
vector<int>pierwsze[LIM], V[LIM], pi;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	rep(i, LIM) jaka[i]=i;
	for(int i=2; i<LIM; ++i) {
		if(pierwsze[i].size()) {
			for(auto j : pierwsze[i]) {
				while(jaka[i]%(j*j)==0) {
					jaka[i]/=j*j;
				}
			}
			continue;
		}
		pi.pb(i);
		for(int j=i; j<LIM; j+=i) {
			pierwsze[j].pb(i);
		}
	}
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		T[i]=jaka[T[i]];
		if(pierwsze[T[i]].size()==0) {
			cout << 1 << '\n';
			return 0;
		} else if(pierwsze[T[i]].size()==1) {
			++ile[T[i]];
		} else {
			int a=pierwsze[T[i]][0], b=pierwsze[T[i]][1];
			V[a].pb(b);
			V[b].pb(a);
		}
	}
	rep(i, LIM) if(ile[i]>=2) {
		cout << 2 << '\n';
		return 0;
	}
	int ans=INF;
	for(auto i : pi) if(i<1000) {
		int s1=INF, s2=INF;
		for(auto j : pi) odl[j]=INF;
		queue<int>q;
		q.push(i);
		odl[i]=0;
		while(!q.empty()) {
			int p=q.front(); q.pop();
			if(ile[p]) {
				if(odl[p]<=s1) {
					s2=s1;
					s1=odl[p];
				} else if(odl[p]<=s2) {
					s2=odl[p];
				}
			}
			int mi1=INF, mi2=INF;
			for(auto j : V[p]) {
				if(odl[j]<=mi1) {
					mi2=mi1;
					mi1=odl[j];
				} else if(odl[j]<=mi2) {
					mi2=odl[j];
				}
			}
			ans=min(ans, mi1+mi2+2);
			for(auto j : V[p]) if(odl[j]>odl[p]+1) {
				odl[j]=odl[p]+1;
				q.push(j);
			}
		}
		ans=min(ans, s1+s2+2);
	}
	if(ans==INF) ans=-1;
	cout << ans << '\n';
}