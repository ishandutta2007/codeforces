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
struct seg{
	long long cnt, sum, ans, l, r;	
	seg(){}
	seg(long long cnt, long long sum, long long ans, long long l, long long r): cnt(cnt), sum(sum), ans(ans), l(l), r(r) {}
	seg operator + (seg A){
		seg B;
		assert(l <= A.l);
		B.cnt = cnt + A.cnt;
		B.sum = sum + A.sum + (A.l - l) * A.cnt;
// 		B.sum = (r - l) * cnt - sum + A.sum + (A.l - l) * A.cnt;
		B.ans = ans + A.ans + ((r - l) * cnt - sum) * A.cnt + A.sum * cnt + (A.l - r) * cnt * A.cnt;
		B.l = l;
		B.r = A.r;
		return B;
	}
	void Epr(){
		cerr << "cnt sum ans " << cnt << " " << sum << " " << ans << " ";
		cerr << "\t\tl r " << l << " " << r << endl;
		
	}
};

struct node{
	node *l, *r;
	int y;
	int cnt;
	seg info;	
	seg sum;
};

int a[maxn];
int b[maxn];

int cnt(node * v){
	return (v == NULL)? 0 : v->cnt;	
}

void upd(node * v){
	v->sum = v->info;
	if (v->l != NULL)
		v->sum = v->l->sum + v->sum;
	if (v->r != NULL)
		v->sum = v->sum + v->r->sum;
	v->cnt = cnt(v->l) + cnt(v->r) + 1;
}

node * merge(node * a, node * b){
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->y > b->y){
		a->r = merge(a->r, b);
		upd(a);
		return a;		
	}
	else{
		b->l = merge(a, b->l);
		upd(b);
		return b;		
	}
}

void split(node * v, node * & l, node * & r, int key){
	if (v == NULL){
		l = NULL;
		r = NULL;
		return;
	}
	pair < node *, node * > t;
	if (key <= v->info.l){
		split(v->l, l, v->l, key);
		upd(v);
		r = v;		
	}
	else{
		split(v->r, v->r, r, key);
		upd(v);
		l = v;
	}
}

void print(node * v, int t = 0){
	if (v->r != NULL) print(v->r, t + 1);
	for (int i = 0; i < t; i++)
		epr("\t");
	v->sum.Epr();
	if (v->l != NULL) print(v->l, t + 1);	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, d, j, m, t, l, r;
	node * head = NULL;
	node * v, * v1, * v2, * v3, * v4;
	/*seg A, B;
	A = seg(2, 1, 1, 0, 1);
	B = seg(2, 1, 1, 3, 4);
	(A + B).Epr();
	return 0;
	*/scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++){
		v = new node;
		v->l = v->r = NULL;
		v->y = rand();
		v->cnt = 1;
		v->info = seg(1, 0, 0, a[i], a[i]);
		v->sum = seg(1, 0, 0, a[i], a[i]);
		head = merge(head, v);		
	}

// 	cerr << head->cnt << endl;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		assert(head->cnt == n);
		scanf("%d", &t);
		if (t == 2){
			scanf("%d%d", &l, &r); r++;
			split(head, v1, v2, l);
			split(v2, v2, v3, r);
			//assert(v2 != NULL);
			if (v2 == NULL)
				cout << 0 << endl;
			else
				cout << v2->sum.ans << endl;
			head = merge(v1, v2);
			head = merge(head, v3);
		}
		if (t == 1){
			scanf("%d%d", &j, &d); j--;
			split(head, v1, v2, b[j]);
			split(v2, v2, v3, b[j] + 1);
			v2->info.l = v2->info.r = b[j] + d;
			v2->sum.l = v2->sum.r = b[j] + d;
			
			if (d > 0){
				split(v3, v3, v4, b[j] + d);
				head = merge(v1, v3);
				head = merge(head, v2);
				head = merge(head, v4);
				
			}
			else{
				split(v1, v1, v4, b[j] + d);
				head = merge(v1, v2);
				head = merge(head, v4);
				head = merge(head, v3);				
			}
			b[j] += d;
		}
	}
 
    return 0;
}