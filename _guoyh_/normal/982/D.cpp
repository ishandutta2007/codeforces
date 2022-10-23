# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
struct Node{
	int nm, id;
	bool operator < (const Node &o) const{
		return nm < o.nm;
	}
} b[NR];
int n, cnt, mx, mn;
int a[NR], p[NR], sz[NR], bx[NR];
int findroot(int x){
	if (!p[x]) return x;
	else return p[x] = findroot(p[x]);
}
void merge(int x, int y){
	int rx = findroot(x), ry = findroot(y);
	bx[sz[rx]]--;
	bx[sz[ry]]--;
	p[ry] = rx;
	sz[rx] += sz[ry];
	bx[sz[rx]]++;
	cnt--;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		b[i] = (Node){a[i], i};
	}
	sort(b + 1, b + n + 1);
	a[0] = b[n].nm + 1;
	for (int i = 1; i <= n; i++){
		int nw = b[i].id;
		sz[nw] = 1;
		bx[1]++;
		cnt++;
		if (nw > 1 && a[nw - 1] < a[nw]) merge(nw, nw - 1);
		if (nw < n && a[nw + 1] < a[nw]) merge(nw, nw + 1);
		if (bx[sz[findroot(nw)]] == cnt && cnt > mx){
			mx = cnt;
			mn = a[nw] + 1;
		}
	}
	printf("%d\n", mn);
	return 0;
}