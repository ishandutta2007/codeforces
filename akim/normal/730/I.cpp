#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = 3020, mod = int(1e9)  + 7;

int n, a[N], b[N], x,y;
pair <pii, int> p[N];
int pref[N];
int cn, dn;

int fp[N], fs[N];
bool used[N];

pair <int,int> c[N], d[N];

int main () {
	scanf("%d", &n);
	scanf("%d %d", &x,&y);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int j = 1; j <= n; j++){
		scanf("%d", &b[j]);
		p[j] = mp(mp(a[j],b[j]), j);
	}
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + p[i].f.f;	
	}
	int ans = 0;
	for(int j = x; j <= x + y; j++){
		cn = 0;
		for(int i = 1; i <= j; i++){
			c[++cn]	= mp(p[i].f.s - p[i].f.f, p[i].s);
		}
		dn = 0;
		for(int i = j + 1; i <= n; i++){
			d[++dn] = mp(p[i].f.s, p[i].s);
		}
		sort(c + 1, c + cn + 1);
		reverse(c + 1, c + cn + 1);
		sort(d + 1, d + dn + 1);
		reverse(d + 1, d + dn + 1);
		int res = pref[j];
		for(int i = 1; i <= j - x; i++){
			res += c[i].f;	
		}
		for(int i = 1; i <= y - (j - x); i++){
			res += d[i].f;
		}
		if(res > ans){
			ans = res;
			memset(used, 0, sizeof(used));
			for(int i = 1; i <= j - x; i++){
				used[c[i].s] = 1;
				fs[i] = c[i].s;
			}
			for(int i = 1; i <= y - (j - x); i++){
				fs[i + (j - x)] = d[i].s;
			}
			int xd = 0;
			for(int i = 1; i <= j; i++) if(!used[p[i].s]){
				fp[++xd] = p[i].s;
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 1; i <= x; i++){
		printf("%d ", fp[i]);
	}
	puts("");
	for(int i = 1; i <= y; i++){
		printf("%d ", fs[i]);
	}
	

return 0;
}