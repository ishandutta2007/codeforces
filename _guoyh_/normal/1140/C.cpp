# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
struct Node{
	ll t, b;
} a[NR];
int n, k;
ll ans;
priority_queue <int> q;
bool cmp(Node x, Node y){
	return x.b > y.b;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].t, &a[i].b);
	sort(a + 1, a + n + 1, cmp);
	ll s = 0;
	for (int i = 1; i <= n; i++){
		if (q.size() < k){
			q.push(-a[i].t);
			s += a[i].t;
		} else if (a[i].t > -q.top()){
			s += a[i].t - (-q.top());
			q.pop();
			q.push(-a[i].t);
		}
		ans = max(ans, s * a[i].b);
	}
	printf("%lld\n", ans);
	return 0;
}