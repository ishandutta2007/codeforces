# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n, m;
int a[NR];
int main(){
	scanf("%d%d", &n, &m);
	int s = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++){
		printf("%d ", (s + a[i]) / m);
		s = (s + a[i]) % m;
	}
	return 0;
}