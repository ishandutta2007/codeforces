#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
int T;
char s[N], t[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		int ans = 0;
		rep(i, 1, n) t[i] = s[i];
		sort(t + 1, t + n + 1);
		rep(i, 1, n) ans += (s[i] != t[i]);
		printf("%d\n", ans);
	}
	return 0;
}