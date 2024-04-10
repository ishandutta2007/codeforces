# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000051;
const int L = 22;
const int U = (1 << L) - 1;
int n;
int a[MAXN];
int f[1 << L];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		f[a[i]] = i;
	}
	for (int i = 0; i < L; i++){
		for (int j = 0; j < (1 << L); j++){
			if ((j >> i) & 1) f[j] = max(f[j], f[j ^ (1 << i)]);
		}
	}
	a[0] = -1;
	for (int i = 1; i <= n; i++) printf("%d ", a[f[U ^ a[i]]]);
	return 0;
}