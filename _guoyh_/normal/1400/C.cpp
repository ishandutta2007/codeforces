# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, x;
char s[NR];
char w[NR];
bool check(int sz){
	for (int i = 1; i <= sz; i++){
		if (s[i] == '1'){
			bool flag = false;
			if (i - x >= 1 && w[i - x] == '1') flag = true;
			if (i + x <= sz && w[i + x] == '1') flag = true;
			if (!flag) return false;
		}
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", s + 1);
		int sz = strlen(s + 1);
		scanf("%d", &x);
		for (int i = 1; i <= sz; i++) w[i] = '1';
		for (int i = 1; i <= sz; i++){
			if (s[i] == '0'){
				if (i - x >= 1) w[i - x] = '0';
				if (i + x <= sz) w[i + x] = '0';
			}
		}
		if (!check(sz)) printf("-1\n");
		else {
			for (int i = 1; i <= sz; i++) printf("%c", w[i]);
			putchar('\n');
		}
	}
	return 0;
}