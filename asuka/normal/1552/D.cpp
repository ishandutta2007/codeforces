#include<bits/stdc++.h>
#define ll long long
#define N 15
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
int T, n, a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		bool flag = 0;
		rep(i, 1, n) {
			if(a[i] == 0) flag = 1;
		}
		int all = (1 << n) - 1;
		rep(s, 1, all) {
			rep(ss, 0, all) {
				if(s & ss) continue;
				int s1, s2;
				s1 = s2 = 0;
				rep(i, 1, n) if((1 << (i - 1)) & s) s1 += a[i];
				rep(i, 1, n) if((1 << (i - 1)) & ss) s2 += a[i];
				if(s1 == s2) {
					flag = 1;
					break;
				}
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}