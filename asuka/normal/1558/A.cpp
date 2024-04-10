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
bool vis[200015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T = 1;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		rep(x, 0, a + b) vis[x] = 0;
		int x = (a + b) / 2;
		rep(p, 0, min(a, x)) {
			if(b - (x - p) < 0) continue;
			vis[a - p + x - p] = 1;
		}
		x = (a + b) - x;
		rep(p, 0, min(a, x)) {
			if(b - (x - p) < 0) continue;
			vis[a - p + x - p] = 1;
		}
		int tot = 0;
		rep(x, 0, a + b) if(vis[x]) tot++;
		printf("%d\n", tot);
		rep(x, 0, a + b) if(vis[x]) printf("%d ", x);
		printf("\n");
		
	}
	return 0;
}