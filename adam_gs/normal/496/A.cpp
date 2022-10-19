#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=107;
int T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	int mi=INT_MAX;
	for(int i=1; i<n-1; ++i) {
		vector<int>V;
		rep(j, n) if(j!=i) V.pb(T[j]);
		int ans=0;
		rep(j, V.size()-1) ans=max(ans, V[j+1]-V[j]);
		mi=min(mi, ans);
	}
	cout << mi << '\n';
}