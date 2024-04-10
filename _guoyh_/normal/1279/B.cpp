# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n, p;
int a[NR];
ll s[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &p);
		int nm = 0, mn, mx = -1;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++){
			s[i] = a[i] + s[i - 1];
			if (a[i] > mx){
				mx = a[i];
				mn = i;
			}
			if (s[i] - mx <= p && s[i] > p) nm = mn;
			if (s[i] - mx > p) break;
		}
		printf("%d\n", nm);
	}
	return 0;
}