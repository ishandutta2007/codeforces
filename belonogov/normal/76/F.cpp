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
	int x, t, id, idM;
	bool flag;
	event(){}
};

event a[maxn];
int tree[maxn * 4];

bool cmpM(event a, event b){
	return a.x - a.t < b.x - b.t;	
}

bool cmpP(event a, event b){
	return a.x + a.t < b.x + b.t || (a.x + a.t == b.x + b.t && a.x - a.t > b.x - b.t);		
}

void init(int v, int ll, int rr, int val){
	if (ll + 1 == rr)
		return void(tree[v] = val);
	init(v * 2 + 1, ll, (ll + rr) / 2, val);
	init(v * 2 + 2, (ll + rr) / 2, rr, val);
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);	
}

void add(int v, int ll, int rr, int pos, int val){
	if (ll >= pos + 1 || pos >= rr)
		return;
	if (ll + 1 == rr)
		return void(tree[v] = val);
	add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
	add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);	
}

int getMax(int v, int ll, int rr, int l, int r){
	if (ll >= r || l >= rr)
		return -inf;
	if (l <= ll && rr <= r)
		return tree[v];
	return max(getMax(v * 2 + 1, ll, (ll + rr) / 2, l, r), 
			   getMax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, ans1 = 0, ans2 = 0, v, cur, r, p = -1, z = -1;
	scanf("%d", &n);
	a[0].x = a[0].t = 0;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i + 1].x, &a[i + 1].t);		
	n++;
	scanf("%d", &v);
	for (int i = 0; i < n; i++)
		a[i].t *= v;
	for (int i = 0; i < n; i++)
		a[i].flag = 0;
	a[0].flag = 1;
	
	sort(a, a + n, cmpM);
	cur = 0;
	for (int i = 0; i < n; i++){
		a[i].idM = cur;		
		if (-a[i].x + a[i].t == 0){
			z = i;
			p = cur;
		}
		if (i + 1 == n || a[i].x - a[i].t != a[i + 1].x - a[i + 1].t)
			cur++;
	}
	a[z] = a[n - 1];
	n--;
	
// 	cerr << "cur: " << cur << endl;
// 	for (int i = 0; i < n; i++){
// 		cerr << a[i].x << " " << a[i].t << " " << a[i].idM << endl;
// 		
// 	}
// 	
	sort(a, a + n, cmpP);

// 	cerr << "cur: " << cur << endl;
// 	for (int i = 0; i < n; i++){
// 		cerr << a[i].x << " " << a[i].t << " " << a[i].idM << endl;
// 		
// 	}
// 	cerr << "p: " << p << endl;
	init(0, 0, cur, -inf);
	add(0, 0, cur, p, 0);
	for (int i = 0; i < n; i++){
		if (a[i].x + a[i].t < 0) continue;
		r = getMax(0, 0, cur, a[i].idM, cur);
		if (r >= 0){
			r++;
			ans1 = max(r, ans1);
			add(0, 0, cur, a[i].idM, r);			
		}
	}
	
	init(0, 0, cur, -inf);
	for (int i = 0; i < n; i++){
		r = getMax(0, 0, cur, a[i].idM, cur);
		r++;
		r = max(1, r);
		ans2 = max(r, ans2);
		add(0, 0, cur, a[i].idM, r);			
	}
	
	cout << ans1 << " " << ans2 << endl;
	
	
	return 0;
}