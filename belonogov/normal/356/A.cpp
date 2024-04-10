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

const int maxn = 3e5 + 2;
const int inf = 1e9;

struct event{
	int pos, type, prior, ans;	
	event(){}
	event(int pos, int type, int prior, int ans): pos(pos), type(type), prior(prior), ans(ans){}
};

event a[maxn * 4];
int b[maxn];
set < pair < int, int > > q;


bool cmp(event a, event b){
	return a.pos < b.pos || (a.pos == b.pos && (a.type > b.type));	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, cur, l, r, x;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &l, &r, &x); l--; r--; x--;
		a[i * 4 + 0] = event(l, 1, i, x);
		a[i * 4 + 1] = event(x, -1, i, x);
		a[i * 4 + 2] = event(x + 1, 1, i, x);
		a[i * 4 + 3] = event(r + 1, -1, i, x);
	}
	sort(a, a + m * 4, cmp);
// 	for (int i = 0; i < m * 4; i++){
// 		epr("%d %d %d %d\n", a[i].pos, a[i].type, a[i].prior, a[i].ans);		
// 	}
	cur = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (; cur < m * 4 && a[cur].pos <= i; cur++){
			if (a[cur].type == 1)
				q.insert(mp(a[cur].prior, a[cur].ans));
			if (a[cur].type == -1)
				q.erase(mp(a[cur].prior, a[cur].ans));
		}
		if (q.empty()){
			cnt++;
			b[i] = -1;				
		}
		if (!q.empty())
			b[i] = q.begin()->second;
		
	}
	assert(cnt == 1);
	for (int i = 0; i < n; i++)
		printf("%d ", b[i] + 1);
	printf("\n");
 
    return 0;
}