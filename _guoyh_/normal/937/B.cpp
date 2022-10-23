# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int p, y;
int main(){
	scanf("%d%d" ,&p, &y);
	for (int i = y; i > p; i--){
		int x = i;
		bool flag = true;
		for (int j = 2; j <= p && j * j <= i; j++){
			if (i % j == 0){
				flag = false;
				break;
			}
		}
		if (flag){
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}