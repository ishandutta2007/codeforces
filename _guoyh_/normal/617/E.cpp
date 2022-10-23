# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
struct Query{
	int lft, rgt, id;
} q[NR];
int n, m, k, nwl = 1, nwr, blen, bsz;
ll tol;
int a[NR], s[NR], bid[NR], mk[NR];
ll ans[NR], bx[1 << 21];
bool cmp(Query x, Query y){
	if (bid[x.lft] != bid[y.lft]) return bid[x.lft] < bid[y.lft];
	else return x.rgt < y.rgt;
}
void move(int tl, int tr){
	while (nwl > tl){
		nwl--;
		tol += bx[s[nwl - 1] ^ k];
		bx[s[nwl - 1]]++;
		// printf("lrt %d %d %d\n", nwl, nwr, tol);
	}
	while (nwr < tr){
		nwr++;
		tol += bx[s[nwr] ^ k];
		bx[s[nwr]]++;
		// printf("lrt %d %d %d\n", nwl, nwr, tol);
	}
	while (nwl < tl){
		bx[s[nwl - 1]]--;
		tol -= bx[s[nwl - 1] ^ k];
		nwl++;
		// printf("lrt %d %d %d\n", nwl, nwr, tol);
	}
	while (nwr > tr){
		bx[s[nwr]]--;
		tol -= bx[s[nwr] ^ k];
		nwr--;
		// printf("lrt %d %d %d\n", nwl, nwr, tol);
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &q[i].lft, &q[i].rgt);
		q[i].id = i;
	}
	blen = int(sqrt(n));
	while (mk[bsz] + blen < n) mk[++bsz] = mk[bsz - 1] + blen;
	mk[++bsz] = n;
	for (int i = 1; i <= bsz; i++){
		for (int j = mk[i - 1] + 1; j <= mk[i]; j++) bid[j] = i;
	}
	sort(q + 1, q + m + 1, cmp);
	bx[s[0]] = 1;
	for (int i = 1; i <= m; i++){
		move(q[i].lft, q[i].rgt);
		ans[q[i].id] = tol;	
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}