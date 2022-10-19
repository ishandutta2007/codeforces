#include<bits/stdc++.h>
#define ll long long
#define N 1015
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
int n, a[N], to[N];
char ans[N][N];
void out(int x) {
	printf("%d\n", x);
	rep(i, 1, n) printf("%s\n", ans[i] + 1);
	exit(0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	bool flag = 1;
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		to[i] = x;
		if(x != i) flag = 0;
		a[i] = i;
	}
	rep(i, 1, n) rep(j, 1, n) ans[i][j] = '.';
	if(flag) out(n);
	int emp = -1;
	per(i, 1, n) {
		if(i == n) {
			int pos = -1;
			rep(j, 1, n) {
				if(to[a[j]] == j) continue;
				if(pos == -1 || to[a[j]] > to[a[pos]]) pos = j;
			}
			a[pos] = 0;
			ans[n][pos] = '/';
			emp = pos;
		} else {
			int pos = -1;
			rep(j, 1, n) {
				if(j < to[a[j]] && to[a[j]] < emp) {
					pos = j;
					break;
				}
			}
			if(~pos) {
				ans[i][pos] = ans[i][to[a[pos]]] = ans[i][emp] = '/';
				a[emp] = a[to[a[pos]]];
				a[to[a[pos]]] = a[pos];
				a[emp = pos] = 0;
			} else {
				rep(j, 1, n) {
					if(to[a[j]] == emp) {
						pos = j;
						break;
					}
				}
				if(~pos) {
					if(pos < emp) ans[i][pos] = ans[i][emp] = '/';
					else ans[i][pos] = ans[i][emp] = '\\';
					a[emp] = a[pos];
					a[emp = pos] = 0;
				}
			}
		}
	}
	out(n - 1);
	return 0;
}