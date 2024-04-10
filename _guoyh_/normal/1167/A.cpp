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
		scanf("%d", &n);
		scanf("%s", s + 1);
		bool flag = false;
		for (int i = 1; i <= n - 10; i++){
			if (s[i] == '8'){
				flag = true;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}