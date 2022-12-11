#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int mdist;

int n;
bool g[1111][1111];

void edge(int a, int b) {
	g[a][b] = g[b][a] = true;
}

void path(int a, int b, int dist) {
	//printf("path %d %d %d\n", a, b, dist);
	for (int i = dist; i < mdist; i++) {
		edge(a, n);
		a = n;
		n++;
	}
	edge(a,b);
}

void go(int beg, int end, int k, int dist) {
	if (k & 1) {
		path(beg, end, dist);
	}
	if (k > 1) {
		edge(beg, n);
		edge(beg, n+1);
		edge(n, n+2);
		edge(n+1, n+2);
		n += 3;
		go(n-1, end, k/2, dist+2);
	}
}

int main() {
	int k;
	scanf("%d", &k);
	n = 2;
	int K = k;
	while (K > 1) {
		mdist += 2;
		K /= 2;
	}
	//printf("mdist = %d\n", mdist);
	go(0,1,k, 0);
	printf("%d\n", n);
	FOR(i,n) {
		FOR(j,n) printf("%c", g[i][j] ? 'Y' : 'N');
		printf("\n");
	}
	return 0;
}