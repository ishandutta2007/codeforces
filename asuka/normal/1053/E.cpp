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
const int N = 1000015;
int n, a[N], fir[N], las[N], fa[N], L[N], R[N];
VI occ[N];
set<int> S;
list<int> seq[N];
void NO() {puts("no"); exit(0);};
void solve(int l, int r) {
	if((r - l) & 1) NO();
	if(a[l] && a[r] && a[l] ^ a[r]) NO();
	a[l] = a[r] = a[l] | a[r];
	S.erase(a[l]);
	if(a[l]) {
		auto it = upper_bound(all(occ[a[l]]), l);
		int lst = l;
		while(it != occ[a[l]].end() && *it < r) {
			solve(lst, *it);
			lst = *it;
			it++;
		}
		if(lst != l) {
			solve(lst, r);
			return;
		}
	}
	set<pii, greater<pii>> q;
	int k = (r - l) / 2 + (a[l] == 0);
	auto construct = [&](int i, int le, int ri) {
		fa[L[i] = le] = fa[R[i] = ri] = i;
		assert(seq[i].size() == 0);
		seq[i].emplace_back(a[i]);
		S.erase(a[i]);
		q.emplace(1, i);
	};
	rep(i, l + 1, r - 1) {
		if(!a[i]) continue;
		if(i != las[a[i]]) {
			if(las[a[i]] > r) NO();
			solve(i, las[a[i]]);
			construct(i, i, las[a[i]]);
			k -= (las[a[i]] - i) / 2;
			i = las[a[i]];
		} else construct(i, i, i);
	}
	if(SZ(q) > k) NO();
	rep(i, l + 1, r - 1) {
		if(SZ(q) == k) break;
		if(!a[i]) {
			if(SZ(S) == 0) NO();
			a[i] = *S.begin(), construct(i, i, i);
		} else i = las[a[i]];
	}
	if(SZ(q) != k) {
		a[l] = a[r] = *S.begin();
		k--;
	}
	while(1) {
		bool flag = 0;
		int u = q.begin() -> se; q.erase(q.begin());
		if(L[u] - 1 > l) {
			if(!a[L[u] - 1] && SZ(seq[u]) > 1) {
				fa[--L[u]] = u;
				seq[u].pop_front();
				a[L[u]] = seq[u].front();
				q.emplace(SZ(seq[u]), u);
				flag = 1;
			} else if(a[L[u] - 1]) {
				int v = fa[L[u] - 1];
				q.erase(mp(SZ(seq[v]), v));
				fa[R[v] = R[u]] = v;
				seq[v].splice(seq[v].end(), seq[u]);
				q.emplace(SZ(seq[v]), v);
				flag = 1;
			}
		} 
		if(!flag && R[u] + 1 < r) {
			if(!a[R[u] + 1] && SZ(seq[u]) > 1) {
				fa[++R[u]] = u;
				seq[u].pop_back();
				a[R[u]] = seq[u].back();
				q.emplace(SZ(seq[u]), u);
				flag = 1;
			} else if(a[R[u] + 1]) {
				int v = fa[R[u] + 1];
				q.erase(mp(SZ(seq[v]), v));
				fa[R[u] = R[v]] = u;
				seq[u].splice(seq[u].end(), seq[v]);
				q.emplace(SZ(seq[u]), u);
				flag = 1;
			}
		}
		if(!flag && q.empty()) {
			q.emplace(SZ(seq[u]), u);
			break;
		}
	}
	if(!a[l]) {
		int u = q.begin() -> se;
		seq[u].pop_front();
		a[l] = a[r] = seq[u].front();
	} else {
		rep(i, l + 1, r - 1) {
			if(!a[i]) a[i] = a[l];
			else i = R[fa[i]];
		}
	}
}
int main() {
	scanf("%d", &n);
	rep(i, 1, n) S.insert(i);
	rep(i, 1, n + n - 1) scanf("%d", &a[i]), S.erase(a[i]), las[a[i]] = i;
	if(n == 1) return puts("yes\n1"), 0;
	rep(i, 1, n + n - 1) if(a[i]) occ[a[i]].emplace_back(i);
	per(i, 1, n + n - 1) fir[a[i]] = i;
	solve(1, n + n - 1);
	puts("yes");
	rep(i, 1, n + n - 1) printf("%d ", a[i]);
	return 0;
}