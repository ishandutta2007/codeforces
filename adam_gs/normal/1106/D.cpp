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
vector<int>V[LIM];
int odw[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	priority_queue<int>q;
	q.push(0);
	odw[0]=1;
	while(!q.empty()) {
		int p=-q.top(); q.pop();
		cout << p+1 << " ";
		for(auto i : V[p]) if(!odw[i]) {
			odw[i]=1;
			q.push(-i);
		}
	}
}