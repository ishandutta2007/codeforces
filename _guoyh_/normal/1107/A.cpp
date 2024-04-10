# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 305;
int t;
int n;
char s[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		if (n == 2 && s[1] >= s[2]){
			printf("NO\n");
			continue;
		}
		printf("YES\n2\n%c %s\n", s[1], s + 2);
	}
	return 0;
}