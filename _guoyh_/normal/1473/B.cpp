# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 25;
int q;
char s[MAXN], t[MAXN];
int main(){
	scanf("%d", &q);
	while (q--){
		scanf("%s%s", s, t);
		int sz1 = strlen(s), sz2 = strlen(t);
		bool flag = false;
		for (int i = 0; i < 21 * sz1; i++){
			if (s[i % sz1] != t[i % sz2]) break;
			if (i != 0 && i % sz1 == 0 && i % sz2 == 0){
				flag = true;
				for (int j = 0; j < i; j++) printf("%c", s[j % sz1]);
				putchar('\n');
				break;
			}
		}
		if (!flag) printf("-1\n");
	}
	return 0;
}//