# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
struct Node{
	int num, id;
	bool operator < (const Node &o) const{
		if (num != o.num) return num < o.num;
		return id < o.id;
	}
} a[200051];
int t;
int d[200051], cl[200051];
int main(){
//	freopen("1.in", "r", stdin);
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%1d", d + i);
			a[i].num = d[i];
			a[i].id = i;
		}
		sort(a + 1, a + n + 1);
		int n1 = 0, n2 = 0, la = 1e9;
		bool suc = true;
		for (int i = 1; i <= n; i++){
//			printf("%d %d %d\n", n1, n2, la);
			if (a[i].num > la || a[i].id < n1){
				if (a[i].id < n2){
					suc = false;
					break;
				}
				n2 = a[i].id;
				cl[a[i].id] = 2;
				la = min(la, a[i].num);
			} else {
				n1 = a[i].id;
				cl[a[i].id] = 1;
			}
		}
		if (!suc) printf("-");
		else for (int i = 1; i <= n; i++) printf("%d", cl[i]);
		putchar('\n');
	}
	return 0;
}