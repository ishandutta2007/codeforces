#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7, LIM=1<<15;
vector<int>V[LIM];
int odl[LIM];
void solve() {
	rep(i, LIM) {
		odl[i]=INF;
		V[(2*i)%LIM].pb(i);
		V[(i+1)%LIM].pb(i);
	}
	odl[0]=0;
	queue<int>q;
	q.push(0);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(auto i : V[p]) if(odl[i]>odl[p]+1) {
			odl[i]=odl[p]+1;
			q.push(i);
		}
	}
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		cout << odl[a] << " ";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}