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
int n, k, a[505], cnt[505];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	if(k == 1) {
		printf("! 1\n");
		return 0;
	}
	n = k + 1;
	rep(i, 1, n) {
		printf("? ");
		rep(j, 1, n) {
			if(i != j) printf("%d ", j);
		}
		printf("\n");
		fflush(stdout);
		int pos, val;
		scanf("%d %d", &pos, &val);
		a[pos] = val;
		cnt[pos]++;
	}
	int p1 = 0, p2 = 0;
	rep(i, 1, n) if(cnt[i] > 0) {
		if(!p1) p1 = i;
		else p2 = i;
	}
	if(a[p1] < a[p2]) swap(p1, p2);
	printf("! %d\n", cnt[p1]);
	fflush(stdout);
	return 0;
}