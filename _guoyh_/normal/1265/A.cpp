# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
const int NR = 100051;
char s[NR];
int la;
int t;
int main(){
//	freopen("1.in", "r", stdin);
	scanf("%d", &t);
	while (t--){
		scanf("%s", s);
		bool suc = true;
		int sz = strlen(s);
		la = -1;
		for (int i = 0; i < sz; i++){
			if (s[i] != '?'){
				if (s[i] == la + 'a'){
					suc = false;
					break;
				}
				la = s[i] - 'a';
			} else {
				la = (la + 1) % 3;
				if (s[i + 1] - 'a' == la) la = (la + 1) % 3;
			}
			s[i] = la + 'a';
		}
		if (suc) printf("%s\n", s);
		else printf("-1\n");
	}
	return 0;
}