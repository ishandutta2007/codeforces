#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e6 + 2;
const int inf = 1e9;

pair < int, int > edge[maxn];
int p[maxn];
int sz[maxn];
set < pair < int, int > > q;
int k;

int getId(int v){
	if (p[v] == v)	return v;
	return p[v] = getId(p[v]);	
}

void merge(int v, int u){
	sz[u] += sz[v];
	p[v] = u;
}

int f(int x){
	return min(x, k);		
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, v, u;
	int tunnel, cnt = 0;
	pair < int, int > a1, a2;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &edge[i].fr, &edge[i].sc); edge[i].fr--; edge[i].sc--;
	}
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		sz[i] = 1;
	cnt = n;
	for (int i = 0; i < m; i++){
		v = getId(edge[i].fr);
		u = getId(edge[i].sc);
		if (v != u){
			merge(v, u);		
			cnt--;			
		}
			
	}
	tunnel = 0;
	for (int i = 0; i < n; i++){
		if (p[i] == i){
			tunnel += f(sz[i]);
			q.insert(mp(sz[i], i));			
		}
	}
	
// 	cerr <<
// 	epr("cnt %d tunnel %d\n", cnt, tunnel);
	for (int i = 0;; i++){
		if (tunnel / 2 >= cnt - 1){
			cout << i << "\n";
			return 0;			
		}
// 		epr("q %d\n", (int)q.size());
		a1 = *q.begin();
		q.erase(q.begin());
		a2 = *q.begin();
		q.erase(q.begin());
		tunnel -= f(a1.fr);
		tunnel -= f(a2.fr);
		tunnel += f(a1.fr + a2.fr);
		q.insert(mp(a1.fr + a2.fr, a1.sc));
		cnt--;		
	}
	
    return 0;
}