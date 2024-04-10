#include<bits/stdc++.h>
#define ll long long
#define N 50015
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
int T, n, r[5][N];
bool cmp(int a, int b) {// ? a < b
	int cnt = 0;
	rep(j, 0, 4) cnt += r[j][a] < r[j][b];
	return cnt >= 3;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			rep(j, 0, 4) scanf("%d", &r[j][i]);
		}
		int lst = 1;
		rep(i, 2, n) {
			if(!cmp(lst, i)) lst = i;
		}
		bool flag = 1;
		rep(i, 1, n) {
			if(i == lst) continue;
			flag &= cmp(lst, i);
		}
		if(flag) printf("%d\n", lst);
		else printf("-1\n");
	}
	return 0;
}