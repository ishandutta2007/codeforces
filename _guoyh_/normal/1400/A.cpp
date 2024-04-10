# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 55;
int t, n;
char s[NR << 2];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++){
			printf("%c", s[i * 2 - 1]);
		}
		putchar('\n');
	}
	return 0;
}