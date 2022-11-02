#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int u[100100];
priority_queue<int> pq;
vector<int> g[100100];
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	pq.push(-1);
	for(int i = 1; i <= n; i++) {
		while(u[-pq.top()]) {
			pq.pop();
		}
		int v = -pq.top();
		pq.pop();
		u[v] = 1;
		for(int j = 0; j < g[v].size(); j++) {
			int to = g[v][j];
			if(!u[to]) pq.push(-to);
		}
		cout << v << " ";
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}