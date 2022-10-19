#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, s, d, a[N];
int f[N];
set<pair<int, int> > S;
set<int> jump;
priority_queue<pair<int, int> > q;

int get(int x) {
	auto it = jump.lower_bound(x);
	int res = inf;
	if(it != jump.end()) res = min(res, *it - x);
	if(it != jump.begin()) {
		it--;
		res = min(res, x - *it);
	}
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		S.insert(mp(a[i], i));
	}
	memset(f, -1, sizeof f);
	q.push(mp(0, s));
	while(!q.empty()) {
		int u = q.top().se;
		int x = q.top().fi;
		q.pop();
		if(f[u] >= 0) continue;
		f[u] = -x;
		rep(p, -1, 1) {
			if(p == 0) continue;
			int to = a[u] + p * d;
			jump.insert(to);
			auto it = S.lower_bound(mp(to, 0));
			if(it != S.end()) {
				q.push(mp(-max(f[u], (*it).fi - to), (*it).se));
			}
			if(it != S.begin()) {
				it--;
				q.push(mp(-max(f[u], to - (*it).fi), (*it).se));
			}
		}
		S.erase(S.find(mp(a[u], u)));
		auto it = S.lower_bound(mp(a[u], u));
		if(it != S.end()) {
			int dis = get((*it).fi);
			q.push(mp(-max(f[u], dis), (*it).se));
		}
		if(it != S.begin()) {
			it--;
			int dis = get((*it).fi);
			q.push(mp(-max(f[u], dis), (*it).se));
		}
	}
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(f[x] <= y) puts("Yes");
		else puts("No");
	}
	return 0;
}