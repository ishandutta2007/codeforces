#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n, m, q, fa[1000015];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {fa[find(u)] = find(v);}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n + m) fa[i] = i;
	rep(i, 1, q) {
		int u, v;
		scanf("%d%d", &u, &v);
		uni(u, v + n);
	}
	int ans = 0;
	rep(i, 1, n + m) if(i == find(i)) ans++;
	printf("%d\n", ans - 1);
	return 0;
}