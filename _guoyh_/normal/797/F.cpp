# include <deque>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 5051;
struct Node{
	int id;
	ll nm;
};
struct Hole{
	ll p, c;
	bool operator < (const Hole &o) const{
		return p < o.p;
	}
} h[MAXN];
int n, m;
ll a[MAXN], s[MAXN], f[MAXN];
deque <Node> q;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= m; i++) scanf("%lld%lld", &h[i].p, &h[i].c);
	sort(a + 1, a + n + 1);
	sort(h + 1, h + m + 1);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= m; i++){
		while (!q.empty()) q.pop_front();
		for (int j = 0; j <= n; j++){
			s[j] = j == 0 ? 0 : s[j - 1] + abs(a[j] - h[i].p);
			while (!q.empty() && q.front().id < j - h[i].c) q.pop_front();
			while (!q.empty() && q.back().nm >= f[j] - s[j]) q.pop_back();
			q.push_back((Node){j, f[j] - s[j]});
			f[j] = s[j] + q.front().nm;
			// printf("f %d %d %d\n", i, j, f[j]);
		}
	}
	if (f[n] > 1e18) printf("-1\n");
	else printf("%lld\n", f[n]);
	return 0;
}