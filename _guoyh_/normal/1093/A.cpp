# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int x;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &x);
		printf("%d\n", x / 2);
	}
	return 0;
}