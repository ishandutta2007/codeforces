# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, z;
char s[100005];
int main(){
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		if (s[i] == 'z') z++;
	for (int i = 1; i <= (n - 4 * z) / 3; i++) printf("1 ");
	for (int i = 1; i <= z; i++) printf("0 ");
	return 0;
}