# include <map>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n;
int p[NR];
map <int, int> mp;
bool check(int x, int y){
	for (int i = x + 1; i <= y; i++)
		if (p[i] != p[i - 1] + 1) return false;
	return true;
}
int main(){
	scanf("%d", &t);
	while (t--){
		bool flag = true;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", p + i);
			mp[p[i]] = i;
		}
		int pos = n, cur = 1;
		while (pos != 0){
			int nw = mp[cur];
			if (!check(nw, pos)){
				flag = false;
				break;
			}
			pos = nw - 1;
			cur = n - pos + 1;
		}
		if (!flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}