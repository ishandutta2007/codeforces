# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
struct Node{
	int x, y;
	Node operator + (const Node &o) const{
		return (Node){x + o.x, y + o.y};
	}
	Node operator - (const Node &o) const{
		return (Node){x - o.x, y - o.y};
	}
};
int n;
Node t;
char st[NR];
Node mv[4] = {(Node){0, 1}, (Node){0, -1}, (Node){-1, 0}, (Node){1, 0}};
Node s[NR];
bool check(int x){
	for (int i = 1; i <= n - x + 1; i++){
		int j = i + x - 1;
		Node nw = t - s[n] + s[j] - s[i - 1];
		if (abs(nw.x) + abs(nw.y) <= x) return true;
	}
	return false;
}
int main(){
	scanf("%d", &n);
	scanf("%s", st + 1);
	scanf("%d%d", &t.x, &t.y);
	for (int i = 1; i <= n; i++){
		switch (st[i]){
			case 'U' : s[i] = s[i - 1] + mv[0]; break;
			case 'D' : s[i] = s[i - 1] + mv[1]; break;
			case 'L' : s[i] = s[i - 1] + mv[2]; break;
			case 'R' : s[i] = s[i - 1] + mv[3]; break;
		}
	}
	if (abs(t.x) + abs(t.y) > n || abs(t.x + t.y - n) & 1){
		printf("-1\n");
		return 0;
	}
	int lft = 0, rgt = n, ans = -1;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		// printf("lrm %d %d %d\n", lft, rgt, mid);
		if (check(mid)){
			ans = mid;
			rgt = mid - 1;
		} else lft = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}