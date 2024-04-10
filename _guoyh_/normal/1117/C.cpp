// submit in luogu
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
struct Node{
	ll x, y;
	Node operator + (const Node &o) const{
		return (Node){x + o.x, y + o.y};
	}
	Node operator - (const Node &o) const{
		return (Node){x - o.x, y - o.y};
	}
	Node operator * (const int &o) const{
		return (Node){x * o, y * o};
	}
};
int n;
char s[NR];
Node mv[4] = {(Node){0, 1}, (Node){0, -1}, (Node){-1, 0}, (Node){1, 0}};
Node st, ed;
Node f[NR];
ll fnl = 1e18;
int main(){
	scanf("%lld%lld%lld%lld", &st.x, &st.y, &ed.x, &ed.y);
	ed = ed - st;
	scanf("%d", &n);
	scanf("%s", s + 1);
	if (ed.x == 0 && ed.y == 0){
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++){
		switch (s[i]){
			case 'U' : f[i] = f[i - 1] + mv[0]; break;
			case 'D' : f[i] = f[i - 1] + mv[1]; break;
			case 'L' : f[i] = f[i - 1] + mv[2]; break;
			case 'R' : f[i] = f[i - 1] + mv[3]; break;
		}
	}
	for (int i = 1; i <= n; i++){
		ll lft = 0, rgt = 1e9, ans = -1;
		while (lft <= rgt){
			ll mid = (lft + rgt) >> 1;
			Node nw = ed - (f[i] + f[n] * mid);
			// printf("lrm %lld %lld %lld %lld %lld\n", lft, rgt, mid, nw.x, nw.y);
			if (abs(nw.x) + abs(nw.y) <= mid * n + i){
				ans = mid;
				rgt = mid - 1;
			} else lft = mid + 1;
		}
		// printf("%d %lld\n", i, ans);
		if (ans != -1) fnl = min(fnl, ans * n + i);
	}
	if (fnl > 1e17) printf("-1\n");
	else printf("%lld\n", fnl);
	return 0;
}