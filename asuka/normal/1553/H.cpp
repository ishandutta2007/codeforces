#include<bits/stdc++.h>
#define ll long long
#define N ((1 << 20) + 10)
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
struct node{
	int Max, Min, len, ans;
};
node merge(node l, node r) {
	node res;
	res.Max = max(l.Max, r.Max + l.len);
	res.Min = min(l.Min, r.Min + l.len);
	res.len = l.len + r.len;
	res.ans = min({l.ans, r.ans, r.Min + l.len - l.Max});
	return res;
}
vector<node> tr[N];
int n, k, cnt[N];
#define ls (p << 1)
#define rs (p << 1 | 1)
void build(int p, int l, int r) {
	tr[p].resize(r - l + 1);
	if(l == r) {
		tr[p][0].len = 1;
		tr[p][0].ans = inf;
		if(cnt[l] > 0) tr[p][0].Max = tr[p][0].Min = 0;
		else tr[p][0].Max = -inf, tr[p][0].Min = inf;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	rep(i, 0, mid - l) {
		tr[p][i] = merge(tr[ls][i], tr[rs][i]);
		tr[p][i + (mid - l + 1)] = merge(tr[rs][i], tr[ls][i]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	build(1, 0, (1 << k) - 1);
	rep(i, 0, (1 << k) - 1) {
		printf("%d ", tr[1][i].ans);
	}
	return 0;
}