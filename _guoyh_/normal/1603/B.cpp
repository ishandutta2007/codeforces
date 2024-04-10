# include <bits/stdc++.h>
# define ll long long
using namespace std;
int t, x, y;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &x, &y);
		swap(x, y);
		if (x < y) printf("%d\n", x + y);
		else if (x == y) printf("%d\n", x);
		else if (x % y) printf("%d\n", x - (x % y) / 2);
		else printf("%d\n", x - y / 2);
	}
	return 0;
}