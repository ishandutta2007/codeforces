# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n, q, cnt;
int a[NR], b[NR], c[NR];
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		cnt -= a[v] == 3;
		a[v] ^= u;
		cnt += a[v] == 3;
		if (u == 1){
			cnt -= b[v] == 3;
			b[v] ^= 1;
			cnt += b[v] == 3;
			cnt -= c[v] == 3;
			c[v] ^= 1;
			cnt += c[v] == 3;
		} else {
			cnt -= b[v + 1] == 3;
			b[v + 1] ^= 2;
			cnt += b[v + 1] == 3;
			cnt -= c[v - 1] == 3;
			c[v - 1] ^= 2;
			cnt += c[v - 1] == 3;
		}
		if (cnt) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}