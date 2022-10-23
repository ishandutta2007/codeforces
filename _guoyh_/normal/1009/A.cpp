# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1051;
int n, m;
int c[NR], a[NR];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	for (int i = 1; i <= m; i++) scanf("%d", a + i);
	int mk = 1;
	for (int i = 1; i <= n && mk <= m; i++){
		if (a[mk] >= c[i]) mk++;
	}
	printf("%d\n", mk - 1);
	return 0;
}