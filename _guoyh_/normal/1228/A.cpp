# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
bool flag[15];
bool check(int x){
	memset(flag, false, sizeof(flag));
	while (x){
		if (flag[x % 10]) return false;
		flag[x % 10] = true;
		x /= 10;
	}
	return true;
}
int main(){
	int l, r;
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++)
		if (check(i)){
			printf("%d\n", i);
			return 0;
		}
	printf("-1\n");
	return 0;
}