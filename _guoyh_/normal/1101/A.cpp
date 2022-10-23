# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		if (d >= l) printf("%d\n", (r / d + 1) * d);
		else printf("%d\n", d);
	}
	return 0;
}