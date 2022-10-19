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
int n, m, a[N];
struct lzjak {
	int line = 0, mov = 0, D[N << 1], up = 0, dn = 0;
	const int sft = 200000;
	void insert(int p) {
		D[p + mov + sft]++;
		if(p + mov > line) up++;
		if(p + mov < line) dn++;
	}
	void move(int v) {
		if(v ==  1) up -= D[line + 1 + sft], dn += D[line + sft];
		if(v == -1) up += D[line + sft], dn -= D[line - 1 + sft];
		line += v;
		mov += v;
	}
} Max, Min;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	Max.line = 1;
	Min.line = 0;
	ll ans = 0;
	rep(i, 1, n) {
		Max.insert(0);
		Min.insert(0);
		Max.move(a[i] >= m ? -1 : 1);
		Min.move(a[i] <= m ? 1 : -1);
		ans += i - Max.dn - Min.up;
	}
	printf("%lld\n", ans);
	return 0;
}