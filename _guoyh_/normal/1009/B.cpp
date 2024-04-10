# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n1, mk = 1e9;
char s[NR];
int main(){
	scanf("%s", s + 1);
	int sz = strlen(s + 1);
	bool flag = false;
	for (int i = 1; i <= sz; i++){
		if (s[i] == '1') n1++;
		if (s[i] == '2') mk = min(mk, i);
	}
	for (int i = 1; i <= sz; i++){
		if (i == mk){
			for (int i = 1; i <= n1; i++) printf("1");
		}
		if (s[i] != '1') printf("%c", s[i]);
	}
	if (mk > sz){
		for (int i = 1; i <= n1; i++) printf("1");
	}
	putchar('\n');
	return 0;
}