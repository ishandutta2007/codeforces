# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int n, k1, k2, w, b;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &k1, &k2);
		int mxw = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
		k1 = n - k1;
		k2 = n - k2;
		int mxb = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
		scanf("%d%d", &w, &b);
		if (w <= mxw && b <= mxb) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}