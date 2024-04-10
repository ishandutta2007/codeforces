# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n;
int p[NR], c[NR];
bool check(){
	if (c[1] > p[1]) return false;
	for (int i = 2; i <= n; i++){
		if (p[i] < p[i - 1]) return false;
		if (c[i] < c[i - 1] || c[i] > c[i - 1] + (p[i] - p[i - 1])) return false;
		if (c[i] > p[i]) return false;
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", p + i, c + i);
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}