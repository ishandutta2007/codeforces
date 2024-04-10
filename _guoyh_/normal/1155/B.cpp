# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n;
char s[NR];
int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	int cnt = 0;
	int mv = (n - 11) / 2;
	for (int i = 1; i <= n; i++){
		if (s[i] == '8') cnt++;
		if (i - cnt > mv) break;
	}
	if (cnt > mv) printf("YES\n");
	else printf("NO\n");
	return 0;
}