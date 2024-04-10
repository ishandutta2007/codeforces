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
vector<pii> construct(char a[]) {
	vector<pii> res;
	for(int l = 1, r; a[l]; l = r + 1) {
		r = l;
		while(a[r + 1] && a[r + 1] == a[l]) r++;
		res.emplace_back(r - l + 1, a[l] - 'a');
	}
	reverse(all(res));
	return res;
}
pii merge(pii u, pii v) {return mp(u.fi + v.fi, u.se);}
void push(vector<pii> &v, pii x) {
	if(SZ(v) == 0 || (SZ(v) > 0 && v.back().se != x.se)) v.pb(x);
	else v[SZ(v) - 1] = merge(v.back(), x);
}
const int N = 200015;
char s[N], t[N];
vector<pii> vs, vt, ans;
void Swap(int x, int y) {
	vector<pii> tmp;
	int ss = 0, st = 0;
	rep(_, 1, x) tmp.pb(vs.back()), ss += vs.back().fi, vs.pop_back();
	per(_, 1, y) push(vs, vt[SZ(vt) - _]);
	rep(_, 1, y) st += vt.back().fi, vt.pop_back();
	rep(_, 1, x) push(vt, tmp.back()), tmp.pop_back();
	ans.emplace_back(ss, st);
}
void G(int x, int y) {
	if(x == 1 and y == 1) return;
	if(x == 1 and y == 2) return Swap(0, 1);
	if(x == 2 and y == 1) return Swap(1, 0);
	if(x == 2 and y == 2) return Swap(1, 2), Swap(1, 0);
	if(x > y) return Swap(2, 1), G(x - 2, y + (y == 1));
	Swap(1, 2);
	return G(x + (x == 1), y - 2);
}
void F(int x, int y) {
	if(x == 1 && y == 1) return;
	if(x + y == 1) return;
	return Swap(1, 1), F(max(1, x - 1), max(1, y - 1));
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s%s", s + 1, t + 1);
	vs = construct(s);
	vt = construct(t);
	bool flag = 0;
	if(SZ(vs) < SZ(vt)) swap(vs, vt), flag = 1;
	if(vs.back().se == vt.back().se) {
		int x = SZ(vt), k = SZ(vs) - SZ(vt);
		if(k >= 2) {
			if(k % 4 == 0) x == 1 ? Swap(x + k / 2 - 1, x) : Swap(x + k / 2 - 2, x - 1);
			else if(k % 4 == 1) Swap(x + k / 2, x - 1);
			else Swap(x + k / 2 - 1, x - 1);
		}
	} else {
		int k = SZ(vs) - SZ(vt), u = (k + 1) / 2;
		if(k >= 2) {
			if(k & 1 && u & 1) u--;
			Swap(u + 1, 1);
		}
	}
	if(vs.back().se == vt.back().se) G(SZ(vs), SZ(vt));
	else F(SZ(vs), SZ(vt));
	printf("%d\n", SZ(ans));
	for(auto x : ans) {
		if(flag) swap(x.fi, x.se);
		printf("%d %d\n", x.fi, x.se);
	}
	return 0;
}
/*
x >= y
f(1, 1) = 0
f(x, y) = max(x - 1, y)
g(x, y) = (x - y) / 2 + y;
S[0] = T[0]
k % 4 == 0 
	x == 1 (x + k / 2 - 1, x)
	else (x + k / 2 - 2, x - 1)
k % 4 == 1 (x + k / 2, x - 1)
k % 4 == 2  (x + k / 2 - 1, x - 1)
k % 4 == 3  (x + k / 2 - 1, x - 1)
*/