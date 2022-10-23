# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int NR = 500051;
int n, ans = 4;
char s[NR];
int main(){
	clock_t t0 = clock();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int p1 = 1, p2 = n;
	while (s[p1] != '[' && p1 < n) p1++;
	p1++;
	while (s[p1] != ':' && p1 < n) p1++;
	while (s[p2] != ']' && p2 > p1) p2--;
	p2--;
	while (s[p2] != ':' && p2 > p1) p2--;
	if (p1 >= p2){
		while (clock() - t0 <= 2970) ans = ans + 1 - 1;
		printf("-1\n");
		return 0;
	}
	for (int i = p1 + 1; i <= p2 - 1; i++){
		if (s[i] == '|') ans++;
	}
	while (clock() - t0 <= 2970) ans = ans + 1 - 1;
	printf("%d\n", ans);
	return 0;
}