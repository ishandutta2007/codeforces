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
int n;
char s[1005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	// scanf("%d", &T);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%s", s + 1);
		int ans = 0;
		int len = strlen(s + 1);
		rep(j, 1, len) ans = max(ans, s[j] - '0');
		printf("%d\n", ans);
	}
	return 0;
}