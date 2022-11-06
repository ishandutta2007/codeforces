#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define LL long long
#define lowbit(x) x &(-x)
template<class T>inline void chkmax(T &x, const T &y) {if(x < y) x = y;}
template<class T>inline void chkmin(T &x, const T &y) {if(y < x) x = y;}
inline int read() {
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = - 1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}

const int N = 5e5 + 5;
int n, k; 
long long f[N][2];

struct edge {
	int to, w;
};

vector<edge> G[N];

struct node {
	long long d, sum;
	bool operator < (const node& rhs) const {
		return d < rhs.d;
	}
};

inline void dfs(int u, int fa) {
	int max1 = 0, max2 = 0; priority_queue<node> q;
	for(int i = 0; i < G[u].size(); ++i) {
		edge x = G[u][i]; if(x.to == fa) continue;
		int v = x.to;
		dfs(v, u);
		q.push((node){f[v][0] + x.w - f[v][1], f[v][1]});
	}
	int cnt = 0, sum;
	while(!q.empty()) {
		cnt ++; node x = q.top(); q.pop();
		f[u][0] += x.sum; f[u][1] += x.sum;
		if(cnt > k || x.d <= 0) {
			continue;
		} else if(cnt == k) {
			f[u][1] += x.d;
		} else {
			f[u][0] += x.d;
			f[u][1] += x.d;
		} 
	}
	//cout << u << " " << f[u][0] << " " << f[u][1] << endl;
}

int main() {
	int T = read();
	while(T--) {
		n = read(); k =read();
		REP(i, 1, n) G[i].clear(), f[i][0] = f[i][1] = 0;
		REP(i, 1, n - 1) {
			int x = read(), y = read(), z = read();
			G[x].push_back((edge){y, z});
			G[y].push_back((edge){x, z});
		}
		dfs(1, -1);
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
	return 0;
}