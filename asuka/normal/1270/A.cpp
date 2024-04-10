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
int T, n, k1, k2, a[105], b[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &k1, &k2);
		rep(i, 1, k1) scanf("%d", &a[i]);
		rep(i, 1, k2) scanf("%d", &b[i]);
		if(*max_element(a + 1, a + k1 + 1) > *max_element(b + 1, b + k2 + 1)) puts("YES");
		else puts("NO");
	}
	return 0;
}