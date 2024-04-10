# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int t;
int p, f, cnts, cntw, s, w;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d%d%d%d", &p, &f, &cnts, &cntw, &s, &w);
		if (s > w){
			swap(s, w);
			swap(cnts, cntw);
		}
		if (p / s + f / s > cnts){
			int ans = 0;
			for (int i = 0; i <= cnts; i++){
				if (i * s > p) break;
				if ((cnts - i) * s > f) continue;
				ans = max(ans, (p - i * s) / w + (f - (cnts - i) * s) / w);
			}
			printf("%d\n", min(ans, cntw) + cnts);
		} else printf("%d\n", p / s + f / s);
	}
	return 0;
}