#include<bits/stdc++.h>
#define ll long long
#define N
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
int t, n, a[200015];
void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) a[i] -= i;
	int Min = inf, pos = -1;
	rep(i, 1, n) {
		if(pos != -1) {
			if(Min < a[i]) {
				puts("YES");
				printf("%d %d\n", pos, i);
				return;
			}
		}
		if(a[i] < Min) Min = a[i], pos = i;
	}
	rep(i, 1, n) a[i] += i * 2;
	Min = inf; pos = -1;
	per(i, 1, n) {
		if(pos != -1) {
			if(Min < a[i]) {
				puts("YES");
				printf("%d %d\n", i, pos);
				return;
			}
		}
		if(a[i] < Min) Min = a[i], pos = i;
	}
	puts("NO");
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}