# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n;
char s[NR];
bool check(){
	for (int i = 1; i + i <= n; i++){
		int df = max(s[i], s[n - i + 1]) - min(s[i], s[n - i + 1]);
		if (df != 0 && df != 2) return false;
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}