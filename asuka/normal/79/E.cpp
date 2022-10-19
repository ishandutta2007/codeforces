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
using corner = array<ll, 4>;
const int N = 200015;
int n, a, b, c;
corner operator + (const corner &l, const corner &r) {return {l[0] + r[0], l[1] + r[1], l[2] + r[2], l[3] + r[3]};}
corner operator - (const corner &l, const corner &r) {return {l[0] - r[0], l[1] - r[1], l[2] - r[2], l[3] - r[3]};}
int X[2][2], Y[2][2];
ll t;
int dis(int x, int y, int a, int b) {return abs(x - a) + abs(y - b);}
corner calc(int x, int y) {
	corner res;
	rep(i, 0, 1) rep(j, 0, 1) res[i * 2 + j] = dis(X[i][j], Y[i][j], x, y);
	return res;
}
ll Dis(int a, int b, int lx, int ly, int rx, int ry) {
	return (ll) (dis(a, b, lx, ly) + dis(a, b, rx, ry)) * (dis(lx, ly, rx, ry) + 1) / 2 - dis(a, b, lx, ly);
}
void out(corner x) {rep(i, 0, 3) printf("%lld ", x[i]); printf("\n");}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%lld%d%d%d", &n, &t, &a, &b, &c);
	rep(i, 0, 1) rep(j, 0, 1) X[i][j] = a + i * (c - 1), Y[i][j] = b + j * (c - 1);
	corner cur = {t, t, t, t};
	int cx = 1, cy = 1;
	string ans;
	while(cx < n || cy < n) {
		function<bool()> check = [&]() {
			corner nxt = cur;
			int nx = cx, ny = cy;
			auto Travel = [&](int tx, int ty, corner& v) {
				rep(i, 0, 1) rep(j, 0, 1) v[i * 2 + j] -= Dis(X[i][j], Y[i][j], nx, ny, tx, ty);
				nx = tx;
				ny = ty;
			};
			if(nx < a) Travel(a, ny, nxt);
			if(ny < b) Travel(nx, b, nxt);
			int ox = -1, oy = -1;
			if(nx < a + c - 1 && ny < b + c - 1) {
				ox = nx; oy = ny;
				nx = a + c - 1;
				ny = b + c - 1;
			}
			if(nx < a + c - 1) Travel(a + c - 1, ny, nxt);
			if(ny < b + c - 1) Travel(nx, b + c - 1, nxt);
			Travel(n, ny, nxt);
			Travel(nx, n, nxt);
			if(*min_element(all(nxt)) < 0) return false;
			if(~ox) {
				corner o = {0, 0, 0, 0};
				nx = ox; ny = oy;
				ll Min1, sum;
				Travel(nx, b + c - 1, o);
				Travel(a + c - 1, b + c - 1, o);
				if(min((nxt + o)[0], (nxt + o)[3]) < 0) return false;	
				Min1 = -o[1]; sum = - o[1] - o[2];
				if(nxt[1] + nxt[2] < sum || nxt[1] < Min1) return false;		
			}
			return true;
		};
		// Try R
		bool flag = 0;
		if(cx < n) {
			cur = cur - calc(++cx, cy);
			if(check()) flag = 1, ans += 'R';
			else cur = cur + calc(cx--, cy);
		}
		if(!flag && cy < n) {
			cur = cur - calc(cx, ++cy);
			if(check()) flag = 1, ans += 'U';
			else cur = cur + calc(cx, cy--);
		}
		if(!flag) return puts("Impossible"), 0;
	}
	for(auto ch : ans) printf("%c", ch);
	return 0;
}