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
		printf("%d\n", n / 2 + 1);
	}
	return 0;
}