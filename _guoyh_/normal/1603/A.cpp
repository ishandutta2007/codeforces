# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
int a[MAXN];
bool check(int pos){
	if (pos >= 31) return true;
	for (int i = pos; i >= 1; i--){
		if (a[pos] % (i + 1)) return true;
	}
	return false;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		bool flag = true;
		for (int i = n; i >= 1; i--){
			if (!check(i)){
				flag = false;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}