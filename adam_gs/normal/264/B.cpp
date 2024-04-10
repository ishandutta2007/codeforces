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
int ma[LIM], p[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		p[a]=1;
	}
	int ans=1;
	for(int i=1; i<LIM; ++i) {
		if(!p[i]) continue;
		int x=0;
		for(int j=2; j*j<=i; ++j) {
			if(i%j==0) {
				x=max(x, ma[j]);
				x=max(x, ma[i/j]);
			}
		}
		++x;
		ans=max(ans, x);
		for(int j=2; j*j<=i; ++j) {
			if(i%j==0) {
				ma[j]=x;
				ma[i/j]=x;
			}
		}
		ma[i]=x;
	}
	cout << ans << '\n';
}