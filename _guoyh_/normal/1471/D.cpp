# include <map>
# include <ctime>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
# define ull unsigned long long
using namespace std;
const int MAXN = 300051;
const int MAXA = 1000051;
int t;
int n, q, psz;
int a[MAXN];
int p[MAXA];
bool flag[MAXA];
ull base;
map <ull, int> mp;
int main(){
	srand(time(0));
	for (int i = 2; i < MAXA; i++){
		if (!flag[i]) p[++psz] = i;
		for (int j = 1; j <= psz && i * p[j] < MAXA; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
	base = (1ull * rand() * rand()) * 2 + 1000033ull;
	scanf("%d", &t);
	while (t--){
		mp.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++){
			ull hsh = 0;
			for (int j = 1; j <= psz && p[j] * p[j] <= a[i]; j++){
				int cnt = 0;
				while (a[i] % p[j] == 0){
					cnt++;
					a[i] /= p[j];
				}
				if (cnt & 1) hsh = hsh * base + (ull)j;
			}
			if (a[i] != 1){
				int pp = lower_bound(p + 1, p + psz + 1, a[i]) - p;
				hsh = hsh * base + (ull)pp;
			}
			if (mp.find(hsh) == mp.end()) mp[hsh] = 1;
			else mp[hsh]++;
			// printf("%d %llu\n", i, hsh);
		}
		int ans1 = 0, ans2 = 0;
		for (map <ull, int>::iterator i = mp.begin(); i != mp.end(); i++){
			ans2 = max(ans2, i -> second);
			if (i -> second % 2 == 0 || i -> first == 0) ans1 += i -> second;
		}
		scanf("%d", &q);
		while (q--){
			ll w;
			scanf("%lld", &w);
			if (w == 0) printf("%d\n", ans2);
			else printf("%d\n", max(ans1, ans2));
		}
	}
	return 0;
}