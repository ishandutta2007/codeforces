# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1051;
int n;
char s[NR];
int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	bool suc = false;
	for (int i = 2; i <= n; i++){
		if (s[i] != s[i - 1]){
			printf("YES\n%c%c\n", s[i - 1], s[i]);
			suc = true;
			break;
		}
	}
	if (!suc) printf("NO\n");
	return 0;
}