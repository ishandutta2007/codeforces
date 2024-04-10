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
int n, a[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n - 1) {
		printf("? ");
		rep(j, 1, n) printf("%d%c", j == n ? (i + 1) : 1, " \n"[j == n]);
		fflush(stdout);
		int k;
		scanf("%d", &k);
		if(k == 0) {
			a[n] = n - i + 1;
			break;
		}
	}
	if(!a[n]) a[n] = 1;
	rep(i, 1, n) {
		if(i == a[n]) continue;
		printf("? ");
		rep(j, 1, n) printf("%d%c", j == n ? (n + 1 - a[n]) : (n + 1 - i), " \n"[j == n]);
		fflush(stdout);
		int k;
		scanf("%d", &k);
		a[k] = i;
	}
	printf("! ");
	rep(i, 1, n) printf("%d ", a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}