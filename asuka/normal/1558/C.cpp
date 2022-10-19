#include<bits/stdc++.h>
#define ll long long
#define N 2205
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int T, n, p[N];
VI vec;
void rev(int x) {
	vec.pb(x);
	rep(i, 1, x / 2) swap(p[i], p[x - i + 1]);
} 
void fuck(int x) {
	if(x == 1) return;
	rep(i, 1, x) {
		if(p[i] == x) {
			rev(i);
			break;
		}
	}
	rep(i, 1, x) if(p[i] == x - 1) {
		rev(i - 1);
		rev(i + 1);
		break;
	}
	rev(3);
	rev(x);
	fuck(x - 2);
}
void solve() {
	vec.clear();
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, n) {
		if((i & 1) != (p[i] & 1)) {
			puts("-1");
			return;
		}
	}
	fuck(n);
	// rep(i, 1, n) printf("%d ", p[i]); printf("\n");
	printf("%d\n", SZ(vec));
	for(auto x : vec) printf("%d ", x); printf("\n");
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}