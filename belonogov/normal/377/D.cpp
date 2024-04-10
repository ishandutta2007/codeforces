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

const int maxn = 1e5 + 2;
const int inf = 1e9;

struct event{
	int type, t, l, r;
	event(){}
	event(int type, int t, int l, int r): type(type), t(t), l(l), r(r){}	
};

int l[maxn];
int r[maxn];
int v[maxn];
event a[maxn * 2];
int tree[maxn * 12];
int upd[maxn * 12];
int pos[maxn * 12];

void push(int v){
	tree[v * 2 + 1] += upd[v];
	tree[v * 2 + 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v * 2 + 2] += upd[v];
	upd[v] = 0;	
}


void add(int v, int ll, int rr, int l, int r, int d){
	if (ll >= r || l >= rr)
		return;
	if (l <= ll && rr <= r){
		tree[v] += d;
		upd[v] += d;
		return;
	}
	push(v);
	add(v * 2 + 1, ll, (ll + rr) / 2, l, r, d);
	add(v * 2 + 2, (ll + rr) / 2, rr, l, r, d);
	if (tree[v * 2 + 1] > tree[v * 2 + 2])
		pos[v] = pos[v * 2 + 1];
	else
		pos[v] = pos[v * 2 + 2];
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void init(int v, int ll, int rr){
	if (ll + 1 == rr){
		pos[v] = ll;
		return;		
	}
	init(v * 2 + 1, ll, (ll + rr) / 2);
	init(v * 2 + 2, (ll + rr) / 2, rr);
	pos[v] = pos[v * 2 + 1];	
}

// int getMax(int v, int ll, int rr, int l, int r){
// 	if (ll >= r || l >= rr)
// 		return -1;
// 	if (l <= ll && rr <= r)
// 		return tree[v];
// 	push(v);
// 	return max(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r),
// 			   getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
// }

bool cmp(event a, event b){
	return a.t < b.t || (a.t == b.t && a.type > b.type);	
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, answer = 0;
	pair < int, int > p;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d%d%d", &l[i], &v[i], &r[i]);
		a[i * 2] = event(1, l[i], v[i], r[i]);
		a[i * 2 + 1] = event(-1, v[i], v[i], r[i]);
	}
	sort(a, a + n * 2, cmp);
	init(0, 0, maxn * 3);
	for (int i = 0; i < n * 2; i++){
		add(0, 0, maxn * 3, a[i].l, a[i].r + 1, a[i].type);
		if (answer < tree[0]){
			answer = tree[0];
			p = mp(a[i].t, pos[0]);			
		}

	}
	cout << answer << endl;
	for (int i = 0; i < n; i++)
		if (l[i] <= p.fr && p.fr <= v[i] && v[i] <= p.sc && p.sc <= r[i])
			printf("%d ", i + 1);
	printf("\n");
	
	
	
    return 0;
}