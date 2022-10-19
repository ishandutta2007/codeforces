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
int n, m, k;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> m >> k;
	if(((ll) 2 * n * m) % k || k == 1) return puts("NO"), 0;
	int p, q, g = __gcd(2 * n, k);
	if(g > 1) p = 2 * n / g, q = m / (k / g);
	else p = n, q = 2 * m / k;
	puts("YES");
	printf("0 0\n%d 0\n0 %d\n", p, q);
	return 0;
}