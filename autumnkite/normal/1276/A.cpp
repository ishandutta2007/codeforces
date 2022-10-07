#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 150005;
int T, n;
char s[N];
void solve(){
	scanf("%s", s + 1), n = strlen(s + 1);
	std::vector<int> pos;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == 'o'){
			int j = i;
			while (j <= n && s[j] == 'o') ++j;
			bool flag1 = (i > 2 && s[i - 2] == 't' && s[i - 1] == 'w'), flag2 = (j < n && s[j] == 'n' && s[j + 1] == 'e');
			if (flag1 && flag2){
				if (j - i >= 2) pos.push_back(i - 1), pos.push_back(j);
				else for (register int k = i; k < j; ++k) pos.push_back(k);
			}
			else if (flag1 || flag2){
				if (j - i >= 1) if (flag1) pos.push_back(i - 1); else pos.push_back(j);
				else for (register int k = i; k < j; ++k) pos.push_back(k);
			}
			i = j;
		}
	printf("%d\n", pos.size());
	for (int v : pos) printf("%d ", v);
	putchar('\n');
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
}