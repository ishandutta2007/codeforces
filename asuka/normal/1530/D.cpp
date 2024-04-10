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
int t, n, a[N], pla[N], b[N], vis[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t -- ){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) pla[i] = b[i] = vis[i] = 0;
		rep(i, 1, n) {
			if(!pla[a[i]]) {
				b[i] = a[i];
				pla[a[i]] = i;
				vis[a[i]] = 1;
			}
		}
		VI v1, v2;
		rep(i, 1, n) if(!b[i]) {
			if(!pla[i]) {
				vis[i] = 2;
			}
		}
		rep(i, 1, n) if(!vis[i]) {
			v1.pb(i);
		}
		rep(i, 1, n) {
			if(!b[i]) {
				if(!pla[i]) {
					v2.pb(i);
				} else {
					v2.pb(v1.back());
					v1.pop_back();
				}
			}
		}
		if(v2.size() == 1) {
			int flag = 0, pos = 0;
			rep(i, 1, n) {
				if(!b[i] && !pla[i]) {
					flag = pla[a[i]];
					pos = i;
				}
			}
			if(flag) {
				b[pos] = a[pos];
				b[flag] = 0;
			}
		}
		int cnt = 0;
		rep(i, 1, n) if(!b[i]) {
			cnt++;
			b[i] = v2[cnt % SZ(v2)];
		}
		int res = 0;
		rep(i, 1, n) if(a[i] == b[i]) res++;
		printf("%d\n", res);
		rep(i, 1, n) printf("%d ", b[i]); printf("\n");
	}
	return 0;
}