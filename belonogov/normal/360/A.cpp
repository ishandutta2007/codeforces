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

const int maxn = 5e3 + 2;
const int inf = 2e8;

int l[maxn];
int r[maxn];
int x[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
int t[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		b[i] = inf;
	for (int i = 0; i < m; i++){
		scanf("%d", &t[i]);
		scanf("%d%d%d", &l[i], &r[i], &x[i]); l[i]--;
		if (t[i] == 1){
			for (int j = l[i]; j < r[i]; j++)
				a[j] += x[i];
		}
		if (t[i] == 2){
			for (int j = l[i]; j < r[i]; j++)
				b[j] = min(b[j], x[i] - a[j]);
		}
	}
	for (int i = 0; i < n; i++)
		c[i] = b[i];
// 	for (int i = 0; i < n; i++)
// 		epr("%d ", a[i]);
// 	epr("\n");
// 	for (int i = 0; i < n; i++)
// 		epr("%d ", b[i]);
// 	epr("\n");
	
	for (int i = 0; i < m; i++){
		if (t[i] == 1){
			for (int j = l[i]; j < r[i]; j++)
				b[j] += x[i];
		}
		if (t[i] == 2){
			int res = -inf;
			for (int j = l[i]; j < r[i]; j++)
				res = max(res, b[j]);
			if (res != x[i]){
				printf("NO\n");
				return 0;				
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
	printf("\n");
	
 
    return 0;
}