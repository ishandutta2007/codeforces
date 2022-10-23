# include <set>
# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll MAXN = 100051;
const ll mo[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
set <pair <ll, ll> > st;
ll n, m, r, k;
ll p;
ll calc(ll x, ll y){
	return (min(x + r - 1, n) - max(x, r) + 1) * (min(y + r - 1, m) - max(y, r) + 1);
}
struct Node{
	ll x, y, d;
	bool operator < (const Node &o) const{
		return d < o.d;
	}
};
priority_queue <Node> q;
int main(){
	scanf("%lld%lld%lld%lld", &n, &m, &r, &k);
	// q.push((Node){0, 0, 1});
	// q.push((Node){0, 0, 0});
	// printf("%lld\n", q.top().d);
	// return 0;
	// printf("%lld\n", calc(1, 1));
	q.push((Node){(n + 1) / 2, (m + 1) / 2, calc((n + 1) / 2, (m + 1) / 2)});
	st.insert(make_pair((n + 1) / 2, (m + 1) / 2));
	for (ll i = 1; i <= k; i++){
		Node nw = q.top();
		q.pop();
		// printf("nw %lld %lld %lld\n", nw.x, nw.y, nw.d);
		p += calc(nw.x, nw.y);
		for (ll j = 0; j < 4; j++){
			Node nxtn = (Node){nw.x + mo[j][0], nw.y + mo[j][1], 0};
			if (nxtn.x <= 0 || nxtn.x > n || nxtn.y <= 0 || nxtn.y > m) continue;
			if (st.find(make_pair(nxtn.x, nxtn.y)) != st.end()) continue;
			// printf("nxtn %lld %lld %lld\n", nxtn.x, nxtn.y, calc(nxtn.x, nxtn.y));
			nxtn.d = calc(nxtn.x, nxtn.y);
			st.insert(make_pair(nxtn.x, nxtn.y));
			q.push(nxtn);
			// printf("qt   %lld %lld %lld\n", q.top().x, q.top().y, q.top().d);
		}
	}
	printf("%.10lf\n", (double)p / ((n - r + 1) * (m - r + 1)));
	return 0;
}