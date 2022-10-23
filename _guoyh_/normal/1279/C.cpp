# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n, m;
int a[NR], b[NR], p[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		int mx = 0;
		ll ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			p[a[i]] = i;
		}
		for (int i = 1; i <= m; i++){
			scanf("%d", b + i);
			if (p[b[i]] > mx){
				mx = p[b[i]];
				ans += 2ll * (p[b[i]] - i);
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}