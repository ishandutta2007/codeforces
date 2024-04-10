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
int n, a[200015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	if(n % 2 == 0) puts("NO");
	else {
		puts("YES");
		rep(i, 1, n) {
			if(i & 1) a[i] = 2 * i - 1, a[n + i] = 2 * i;
			else a[i] = 2 * i, a[n + i] = 2 * i - 1;
		}
		rep(i, 1, n * 2) printf("%d ", a[i]);
	}
	return 0;
}