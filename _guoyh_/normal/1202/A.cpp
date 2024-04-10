# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t;
char s1[MAXN], s2[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s%s", s1 + 1, s2 + 1);
		int sz1 = strlen(s1 + 1), sz2 = strlen(s2 + 1);
		int pos = 1;
		for (int i = 1; i <= sz2; i++){
			if (s2[sz2 - i + 1] == '1'){
				pos = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 1; pos + i - 1 <= sz1; i++){
			if (s1[sz1 - pos - i + 2] == '1'){
				ans = i - 1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}