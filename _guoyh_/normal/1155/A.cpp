# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
int n;
char s[NR];
int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 2; i <= n; i++){
		if (s[i - 1] > s[i]){
			printf("YES\n%d %d\n", i - 1, i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}