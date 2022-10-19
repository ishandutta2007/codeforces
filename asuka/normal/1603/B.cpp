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
int t, x, y;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &x, &y);
		if(x <= y) {
			int v = (x + y) / 2;
			if(v % x == y % v) {
				printf("%d\n", v);
			} else {
				int k = y % x;
				k /= 2;
				printf("%d\n", y - k);
			}
		} else printf("%d\n", x + y);
	}
	return 0;
}