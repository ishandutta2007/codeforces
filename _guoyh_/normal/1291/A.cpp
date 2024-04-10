# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int o[3], t, n;
int a[3051];
int cnte, cnto;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%1d", a + i);
		cnto = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] & 1){
				o[++cnto] = a[i];
			}
			if (cnto >= 2){
				printf("%d%d\n", o[1], o[2]);
				break;
			}
		}
		if (cnto < 2) printf("-1\n");
	}
	return 0;
}