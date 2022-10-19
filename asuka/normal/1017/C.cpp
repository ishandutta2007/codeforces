#include<bits/stdc++.h>
#define ll long long
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
const int N = 100015;
int n, a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	int m = 0, ans = inf;
	rep(i, 1, n) {
		if(i + (n + i - 1) / i < ans) {
			ans = i + (n + i - 1) / i;
			m = i;
		}
	}
	for(int l = 1; l <= n; l += m) {
		int o = min(m, n - l + 1);
		rep(i, 1, o) a[l + i - 1] = o - i + 1 + ((l - 1) / m) * m;
	}
	rep(i, 1, n) printf("%d ", a[i]);
	return 0;
}