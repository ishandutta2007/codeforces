# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n;
int a[300051];
bool check(){
	int pos = n + 1, l;
	for (int i = 1; i <= n; i++){
		if (a[i] < i - 1){
			pos = i;
			break;
		}
	}
	l = a[pos - 1];
	for (int i = pos; i <= n; i++){
		if (l - 1 < 0) return false;
		l = min(a[i], l - 1);
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		if (check()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}