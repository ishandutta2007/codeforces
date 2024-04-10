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

const int maxn = 200 + 2;
const int maxm = 5e4 + 2;
const long long inf = 2e18 + 100;

struct road{
	int v, u, a, b;	
};

road a[maxm];
road b[maxn];
int p[maxn];

int getId(int v){
	return (p[v] == v)? v : p[v] = getId(p[v]);	
}


bool cmpG(road a, road b){
	return a.a < b.a;	
}

bool cmpS(road a, road b){
	return a.b < b.b;	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int m, g, s, cur, cur1, n, v, u, comp;
	long long ans = inf;
	scanf("%d%d%d%d", &n, &m, &g, &s);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d%d", &a[i].v, &a[i].u, &a[i].a, &a[i].b); 
		a[i].v--;
		a[i].u--;
	}
	sort(a, a + m, cmpG);
	cur = 0;
	for (int i = 0; i < m; i++){
		b[cur++] = a[i];
		for (int j = cur - 1; j > 0; j--)
			if (b[j - 1].b > b[j].b)
				swap(b[j], b[j - 1]);
		for (int j = 0; j < n; j++) 
			p[j] = j;
		cur1 = 0;
		comp = n;
		for (int j = 0; j < cur; j++){
			v = getId(b[j].v);
			u = getId(b[j].u);
			if (v != u){
				comp--;
				p[v] = u;
				b[cur1++] = b[j];				
			}
		}
		cur = cur1;
		if (comp == 1)
			ans = min(ans, 1ll * g * a[i].a + 1ll * s * b[cur - 1].b);			
	}
	if (ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
    return 0;
}