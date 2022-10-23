# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n;
char s[NR];
int work(){
	for (int i = 1; i <= n; i++){
		if (s[i] > s[i + 1]) return i;
	}
	return n;
}
int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	int nm = work();
	for (int i = 1; i <= n; i++) if (nm != i) printf("%c", s[i]);
	putchar('\n');
	return 0;
}