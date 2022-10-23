# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t;
char s[NR];
int nm;
int cnt1, cnt2, cnt3;
int main(){
	scanf("%d", &t);
	while (t--){
		cnt1 = cnt2 = cnt3 = nm = 0;
		scanf("%s", s + 1);
		int sz = strlen(s + 1);
		for (int i = 1; i <= sz; i++){
			if (s[i] >= 'a' && s[i] <= 'z'){
				if (!cnt1++) nm++;
			} else if (s[i] >= 'A' && s[i] <= 'Z'){
				if (!cnt2++) nm++;
			} else if (s[i] >= '0' && s[i] <= '9'){
				if (!cnt3++) nm++;
			}
		}
		// printf("%d %d %d\n", cnt1, cnt2, cnt3);
		if (nm == 3){
			printf("%s\n", s + 1);
		} else if (nm == 2){
			char c;
			if (!cnt1) c = 'a';
			else if (!cnt2) c = 'A';
			else c = '0'; 
			for (int i = 1; i <= sz; i++){
				if (s[i] >= 'a' && s[i] <= 'z'){
					if (cnt1 > 1 && nm == 2){
						nm++;
						s[i] = c;
					}
				} else if (s[i] >= 'A' && s[i] <= 'Z'){
					if (cnt2 > 1 && nm == 2){
						nm++;
						s[i] = c;
					}
				} else if (s[i] >= '0' && s[i] <= '9'){
					if (cnt3 > 1 && nm == 2){
						nm++;
						s[i] = c;
					}
				}
			}
			printf("%s\n", s + 1);
		} else {
			if (cnt1) printf("A0");
			else if (cnt2) printf("a0");
			else printf("aA");
			printf("%s\n", s + 3);
		}
	}
	return 0;
}