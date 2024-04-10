# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n;
char s[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		int mx = 0, mi = 1e9;
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++){
			if (s[i] == '>') mi = min(mi, i);
			else mx = max(mx, i);
		}
		printf("%d\n", min(mi - 1, n - mx));
	}
	return 0;
}