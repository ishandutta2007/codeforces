#include<bits/stdc++.h>
#define ll long long
#define N 400015
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
int t, n, a[N], b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		reverse(a + 1, a + n + 1);
		reverse(b + 1, b + n + 1);
		rep(i, 1, n) a[i] += a[i - 1];
		rep(i, 1, n) b[i] += b[i - 1];
		int ans = 0;
		rep(i, 0, n * 3) {
			int suma = i * 100 + a[n - ((n + i) / 4)];
			int sumb = b[min(n, (n + i) - ((n + i) / 4))];
			if(suma >= sumb) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}