# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1051;
int t, n, m;
int a[MAXN], b[MAXN];
bool work(){
	bool flag = true;
	for (int i = 1; i <= n; i++){
		if (a[i] == 1) b[i] = 1;
		else if ((a[i - 1] == 1) ^ (a[i + 1] == 1)){
			b[i] = 1;
			flag = false;
		} else b[i] = 0;
	}
	memcpy(a, b, sizeof(int) * (n + 1));
	return flag;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%1d", a + i);
		a[0] = a[n + 1] = 0;
		for (int i = 1; i <= m; i++){
			if (work()) break;
		}
		for (int i = 1; i <= n; i++) printf("%d", a[i]);
		putchar('\n');
	}
	return 0;
}