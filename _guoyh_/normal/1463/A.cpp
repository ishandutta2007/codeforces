# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, a, b, c;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &a, &b, &c);
		int mi = min(a, min(b, c));
		int s = a + b + c - mi * 3;
		if (s <= 6 * mi && (6 * mi - s) % 9 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}