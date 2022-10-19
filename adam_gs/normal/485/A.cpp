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
const int LIM=1e5+7, INF=1e9+7;
int odw[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, m;
	cin >> x >> m; x%=m;
	while(!odw[x]) {
		odw[x]=1;
		x*=2;
		x%=m;
		if(x==0) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}