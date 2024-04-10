# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n;
char s[NR], s1[NR], s2[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int sz1 = 0, sz2 = 0;
		for (int i = 1; i <= n; i++){
			if ((s[i] - 'a') & 1) s1[++sz1] = s[i];
			else s2[++sz2] = s[i];
		}
		sort(s1 + 1, s1 + sz1 + 1);
		sort(s2 + 1, s2 + sz2 + 1);
		s1[sz1 + 1] = s2[sz2 + 1] = 0;
		if (!sz1) printf("%s\n", s2 + 1);
		else if (!sz2) printf("%s\n", s1 + 1);
		else if (abs(s2[1] - s1[sz1]) != 1) printf("%s%s\n", s1 + 1, s2 + 1);
		else if (abs(s1[1] - s2[sz2]) != 1) printf("%s%s\n", s2 + 1, s1 + 1);
		else printf("No answer\n");
	}
	return 0;
}