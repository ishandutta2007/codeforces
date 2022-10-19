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
int n, a[N], dp[N], from[N], bel[N], tot;
pii A[N];
void out(int x) {
	if(x == 0) return;
	int y = from[x];
	++tot;
	rep(i, y + 1, x) bel[A[i].se] = tot;
	out(y);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) A[i] = mp(a[i], i);
	sort(A + 1, A + n + 1);
	rep(i, 1, n) a[i] = A[i].fi;
	rep(i, 0, n) dp[i] = -inf;
	dp[0] = 0;
	int Max = -inf, pos = -1;
	rep(i, 1, n) {
		if(i - 3 >= 0) {
			int val =  dp[i - 3] + ((i == 3) ? 0 : (a[i - 2] - a[i - 3]));
			if(val > Max) {
				Max = val;
				pos = i - 3;
			}
		}
		dp[i] = Max;
		from[i] = pos;
	}
	out(n);
	printf("%d %d\n", a[n] - a[1] - dp[n], tot);
	rep(i, 1, n) printf("%d ", bel[i]);
	return 0;
}