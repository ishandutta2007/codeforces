#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define y1 qwqwqwqw

using namespace std;

const int maxn = 5e5 + 11;
const ll mod = 998244353;

int a[maxn], f[maxn], cost[maxn];
pair <int, int> e[maxn];
vector < int > go[maxn];
int togo[maxn];
int n;
long long total;
int m,ans;
priority_queue<int> q;

void doit(int x) {
 	total = total + a[x];
 	for (int i = 0; i < go[x].size(); i++) {
 	 	int to = go[x][i];
 	 	if (to <= total) {
 	 	 	total -= to;
 	 	 	q.push(to);
 	 	 	ans++;
 	 		continue;
 	 	}
 	 	if (q.size() > 0 && q.top() > to) {
 	 	     total += q.top() - to;
 	 		q.pop();
 	 	  	q.push(to);
 	 	}
 	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--)
		f[i] = max(f[i + 1], a[i]);
	for (int i = 1; i <= m; i++) {
	    scanf("%d", &e[i].f);
	    e[i].s = i;
	}	
	for (int i = 1; i <= m; i++) 
		scanf("%d", &cost[i]);
	sort(e + 1, e + 1 + m);

	int pos = n;
	for (int i = 1; i <= m; i++) {
	 	while (pos >=  1 && f[pos] < e[i].f ) {
	 	 	pos--;
	 	}
	 	togo[i] = pos;
	}

	for (int i = 1; i <= m; i++) {
	 	if (togo[i] > 0)
	 		go[togo[i]].pb(cost[e[i].s]);
	}
	for (int i = 1; i <= n; i++)
		sort(go[i].begin(), go[i].end());

	for (int i = 1; i <= n; i++) {
	 	doit(i);
	}


	cout << ans;

	return 0;
}