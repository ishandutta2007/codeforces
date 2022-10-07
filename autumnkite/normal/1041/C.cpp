#include <cstdio>
#include <set>
using std :: set;
int n, m, d, a[200005], ans, day[200005];
struct node{
	int val, id;
	bool operator < (const node &res) const {
		return val < res.val;
	}
};
set<node> s;
int main(){
	scanf("%d%d%d", &n, &m, &d);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i), s.insert((node){a[i],i});
	while (!s.empty()){
		set<node> :: iterator it = s.begin(), last;
		++ans;
		while (it != s.end())
			day[(*it).id] = ans, last = it, it = s.upper_bound((node){(*it).val + d, 0}), s.erase(last);
	}
	printf("%d\n", ans);
	for (register int i = 1; i <= n; ++i) printf("%d ", day[i]);
}