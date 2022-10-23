# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 5051;
int n;
int h[NR];
int solve(int l, int r, int d){
	if (l > r) return 0;
	int mi = 1e9 + 2, mn;
	for (int i = l; i <= r; i++){
		if (h[i] < mi){
			mi = h[i];
			mn = i;
		}
	}
	int tol = solve(l, mn - 1, h[mn]) + solve(mn + 1, r, h[mn]) + h[mn] - d;
	return min(tol, r - l + 1);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", h + i);
	printf("%d\n", solve(1, n, 0));
	return 0;
}