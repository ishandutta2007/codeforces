# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		if (n & 1) printf("7");
		else printf("1");
		for (int i = 1; i < n / 2; i++) printf("1");
		putchar('\n');
	}
	return 0;
}