# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1051;
int t, n, len;
int a[MAXN], b[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		len = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++){
			if (a[i] == 1) b[++len] = 1;
			else {
				for (int j = len; j >= 1; j--){
					if (b[j] == a[i] - 1){
						b[j] = a[i];
						len = j;
						break;
					}
				}
			}
			for (int i = 1; i < len; i++) printf("%d.", b[i]);
			printf("%d\n", b[len]);
		}
	}
	return 0;
}