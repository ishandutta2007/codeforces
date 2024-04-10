# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int l, r;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &l, &r);
		printf("%d %d\n", l, l * 2);
	}
	return 0;
}