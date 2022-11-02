#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
#define x1 sfdgdsfg
#define y1 sfdgdsfgasd

#define x2 sfdgdsfg2
#define y2 sfdgdsfgasd2

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int n, m;
int x, y;
int a[100100];
int b[100100];
int v;
int x1, x2, y1, y2;

int calc1(int x1, int y1, int x2, int y2){
	if(x2 == x1) return y2 - y1;
	if(x == 0) return inf;
	int pos = lower_bound(a, a + x, y1) - a;
	if(pos < x && a[pos] <= y2){
		return abs(x2 - x1) + y2 - y1;
	}
	int ans = inf;
	if(pos < x){
		ans = min(ans, abs(x2 - x1) + a[pos] - y1 + a[pos] - y2);
	}
	if(pos > 0){
		ans = min(ans, abs(x2 - x1) - a[pos-1] + y2 + y1 - a[pos-1]);
	}
	return ans;
}

int calc2(int x1, int y1, int x2, int y2){	
	if(x2 == x1) return y2 - y1;
	if(y == 0) return inf;
	int pos = lower_bound(b, b + y, y1) - b;
	if(pos < y && b[pos] <= y2){
		return (abs(x2 - x1) + v - 1)/v + y2 - y1;
	}
	int ans = inf;
	if(pos < y){
		ans = min(ans, b[pos] - y1 + b[pos] - y2);
	}
	if(pos > 0){
		ans = min(ans,  -b[pos-1] + y2 + y1 - b[pos-1]);
	}
	return ans + (abs(x2 - x1) + v - 1)/v;
}
void solve(){
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &v);
	for(int i=0; i < x; i++) scanf("%d", &a[i]);
	for(int i=0; i < y; i++) scanf("%d", &b[i]);
	sort(a, a + x);
	sort(b, b + y);
	int q;
	scanf("%d", &q);
	for(int i=0; i < q; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		//swap(x1, y1);
		//swap(x2, y2);
		if(y1 > y2){
			swap(x1, x2);
			swap(y1, y2);
		}
		printf("%d\n", min(calc1(x1, y1, x2, y2), calc2(x1, y1, x2, y2)));
	}
}
int main () {
	
	int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}