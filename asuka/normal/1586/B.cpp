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
bool vis[100015];
int T, n, m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, m) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			vis[b] = 1;
		}
		int pos = -1;
		rep(i, 1, n) if(!vis[i]) pos = i;
		rep(i, 1, n) {
			if(i == pos) continue;
			printf("%d %d\n", pos, i);
		}
	}
	return 0;
}