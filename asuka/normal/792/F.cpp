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
struct P{int x, y;};
P operator -(const P &u, const P &v) {return (P) {u.x - v.x, u.y - v.y};}
ll operator &(const P &u, const P &v) {return (ll) u.x * v.y - (ll) u.y * v.x;}
bool operator <(const P &u, const P &v) {return u.x != v.x ? u.x < v.x : u.y < v.y;}
int q;
ll m;
set<P> S;
void ins(P x) {
	auto it = S.lower_bound(x), pre = prev(it);
	if(it != S.end() && ((x - (*pre)) & ((*it) - x)) < 0) return;
	if(it != S.end()) while(next(it) != S.end() && (((*it) - x) & ((*next(it)) - (*it))) < 0) it = S.erase(it);
	while(pre != S.begin() && (((*pre) - (*prev(pre))) & (x - (*pre))) < 0) --pre, S.erase(next(pre));
	S.insert(x);
}
bool query(int t, int h) {
	auto i1 = S.lower_bound((P) {(h + t - 1) / t, 0}), i0 = prev(i1);
	if(i1 == S.end()) return 0;
	return (ll) t * ( (ll) i0 -> y * i1 -> x - (ll) i1 -> y * i0 -> x) + (ll) h * (i1 -> y - i0 -> y) <= (ll) m * (i1 -> x - i0 -> x);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%lld", &q, &m);
	int lans = 0;
	S.insert((P) {0, 0});
	rep(_, 1, q) {
		int opt, a, b;
		scanf("%d%d%d", &opt, &a, &b);
		a = (a + lans) % 1000000 + 1;
		b = (b + lans) % 1000000 + 1;
		if(opt == 1) ins((P) {a, b});
		else {
			if(query(a, b)) puts("YES"), lans = _;
			else puts("NO");
		}
	}
	return 0;
}