# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1051;
int t;
char s[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", s + 1);
		int sz = strlen(s + 1);
		sort(s + 1, s + sz + 1);
		if (s[sz] == s[1]) printf("-1\n");
		else printf("%s\n", s + 1);
	}
	return 0;
}