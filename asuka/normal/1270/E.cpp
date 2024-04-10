#include<bits/stdc++.h>
#define ll long long
#define N 10005
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
int n, x[N], y[N];
void out(VI vec) {
	printf("%d\n", SZ(vec));
	for(auto x : vec) printf("%d ", x);
	exit(0);
}
void fuck(int &x) {
	if(x & 1) x--;
	x /= 2;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	while(1) {
		VI vec;
		rep(i, 1, n) if((x[i] + y[i]) % 2 == 0) vec.pb(i);
		if(0 < SZ(vec) && SZ(vec) < n) out(vec);
		vec.clear();
		rep(i, 1, n) if(x[i] % 2 == 0) vec.pb(i);
		if(0 < SZ(vec) && SZ(vec) < n) out(vec);
		vec.clear();
		rep(i, 1, n) fuck(x[i]), fuck(y[i]);
	}
	return 0;
}