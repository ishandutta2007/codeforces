#include<bits/stdc++.h>
#define ll long long
#define N 205
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
int T, n, k, l[N], r[N], vis[N];
VI vec;
bool in(int L, int R, int x){
	return L <= x && x <= R;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n * 2) vis[i] = 0;
		rep(i, 1, k) {
			scanf("%d%d", &l[i], &r[i]);
			if(l[i] > r[i]) swap(l[i], r[i]);
			vis[l[i]] = vis[r[i]] = 1;
		}
		vec.clear();
		rep(i, 1, n * 2) if(!vis[i]) vec.pb(i);
		rep(i, 0, SZ(vec) - 1) {
			l[k + i + 1] = vec[i];
			r[k + i + 1] = vec[i + (n - k)];
		}
		int ans = 0;
		rep(i, 1, n) {
			rep(j, i + 1, n) {
				if(in(l[i], r[i], l[j]) ^ in(l[i], r[i], r[j])) 
					ans++;	
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}