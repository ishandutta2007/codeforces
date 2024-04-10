# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
struct Dat{
	int s, ln, rn;
	bool flag;
	Dat(){
		s = ln = rn = 0;
		flag = false;
	}
	Dat(int s, int ln, int rn, bool flag): s(s), ln(ln), rn(rn), flag(flag){}
	Dat operator + (const Dat &o) const{
		Dat ans;
		ans.s = max(max(s, o.s), rn + o.ln);
		ans.ln = flag ? ln + o.ln : ln;
		ans.rn = o.flag ? o.rn + rn : o.rn;
		ans.flag = flag && o.flag;
		return ans;
	}
};
struct Tree{
	Dat s;
	int ls, rs;
} t[NR * 30];
struct Node{
	int nm, pos;
	bool operator < (const Node &o) const{
		return nm > o.nm;
	}
} a[NR];
int n, m, tsz;
int rt[NR];
void update(int nw){
	t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
}
int modify(int nw, int lft, int rgt, int pos){
	int newn = ++tsz;
	t[newn] = t[nw];
	if (lft == rgt){
		t[newn].s = Dat(1, 1, 1, true);
		return newn;
	}
	int mid = (lft + rgt) >> 1;
	if (pos <= mid) t[newn].ls = modify(t[nw].ls, lft, mid, pos);
	else t[newn].rs = modify(t[nw].rs, mid + 1, rgt, pos);
	update(newn);
	return newn;
}
Dat getlen(int nw, int lft, int rgt, int l, int r){
	if (!nw) return Dat();
	if (lft == l && rgt == r) return t[nw].s;
	int mid = (lft + rgt) >> 1;
	Dat ans;
	if (r <= mid) ans = getlen(t[nw].ls, lft, mid, l, r);
	else if (l >= mid + 1) ans = getlen(t[nw].rs, mid + 1, rgt, l, r);
	else ans = getlen(t[nw].ls, lft, mid, l, mid) + getlen(t[nw].rs, mid + 1, rgt, mid + 1, r);
	// printf("getlen %d %d %d %d %d %d %d\n", lft, rgt, l, r, ans.s, ans.ln, ans.rn);
	return ans;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i].nm);
		a[i].pos = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		rt[i] = modify(rt[i - 1], 1, n, a[i].pos);
		// printf("s %d %d %d %d\n", i, t[rt[i]].s.s, t[rt[i]].s.ln, t[rt[i]].s.rn);
	}
	scanf("%d", &m);
	while (m--){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		int l = 1, r = n, ans = -1;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (getlen(rt[mid], 1, n, u, v).s >= w){
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		printf("%d\n", a[ans].nm);
	}
	return 0;
}