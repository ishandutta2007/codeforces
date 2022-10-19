#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int t, n, a[N], ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) ans[i] = a[i + 1], ans[i + 1] = -a[i];
		} else {
			for (int i = 4; i <= n; i += 2) ans[i] = a[i + 1], ans[i + 1] = -a[i];
			if (abs(a[1]) == abs(a[2]) && abs(a[2]) == abs(a[3])) {
				ans[1] = ans[2] = 1;
				ans[3] = -2;
			} else {
				bool tt = 0;
				if (abs(a[1]) == abs(a[2])) tt = 1, swap(a[2], a[3]);
				if (abs(a[1]) + abs(a[2]) <= 10000) ans[1] = 1, ans[2] = 1;
				else ans[1] = 1, ans[2] = -1;
				int sum = abs(a[1]) * ans[1] + abs(a[2]) * ans[2];
				ans[3] = -sum;
				ans[1] *= abs(a[3]);
				ans[2] *= abs(a[3]);
				if (tt) swap(a[2], a[3]), swap(ans[2], ans[3]);
			}
			if (a[1] < 0) ans[1] = -ans[1];
			if (a[2] < 0) ans[2] = -ans[2];
			if (a[3] < 0) ans[3] = -ans[3];
		}
		rep(i, 1, n) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}