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
const int N = 1015;
int n;
pii a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		int x, sum = 0;
		rep(_, 0, 3) scanf("%d", &x), sum += x;
		a[i] = mp(sum, i);
	}
	sort(a + 1, a + n + 1, [](pii u, pii v) {
		return u.fi != v.fi ? u.fi > v.fi : u.se < v.se;
	});
	rep(i, 1, n) if(a[i].se == 1) printf("%d\n", i);
	return 0;
}