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

const int maxn = 2e5 + 2;
const int inf = 1e5 + 100;

struct event{
	int type, x, l, c, sz;	
};

event a[maxn];
int b[maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int m, n, cur = 0, cur1;
	long long cnt = 0, q;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &a[i].type);
		if (a[i].type == 1){
			scanf("%d", &a[i].x);
			a[i].sz = 1;			
		}
		if (a[i].type == 2){
			scanf("%d%d", &a[i].l, &a[i].c);
			a[i].sz = a[i].l * a[i].c;			
		}
	}
	for (int i = 0; i < m && cur <= inf; i++){
		if (a[i].type == 1)
			b[cur++] = a[i].x;
		if (a[i].type == 2){
			for (int j = 0; j < a[i].c && cur < inf; j++)
				for (int k = 0; k < a[i].l && cur < inf; k++)
					b[cur++] = b[k];
		}
	}
 
	scanf("%d", &n);
	cur1 = 0;
	for (int i = 0; i < n; i++){
		scanf("%I64d", &q); q--;
		for (;cnt + a[cur1].sz <= q; cnt += a[cur1].sz, cur1++);
		if (a[cur1].type == 1)
			cout << a[cur1].x << " ";
		else{
			cout << b[(q - cnt) % a[cur1].l] << " ";			
		}
	}
	cout << endl;
 
    return 0;
}