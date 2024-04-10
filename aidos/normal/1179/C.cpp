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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int a[300300];
int b[300300];
int t[4*1000100];
int sum[4*1000100];
int N = 1000010;
int q;
void add(int v, int l, int r, int p, int x){
	if(l==r){
		sum[v] += x;
		t[v] = sum[v];
		return;
	}
	int mid = (l+r)>>1;
	if(p <= mid) add(v*2, l, mid, p, x);
	else add(v * 2 + 1, mid + 1, r, p, x);
	sum[v] = sum[v*2] + sum[v * 2+1];
	t[v] = min(t[v*2+1], t[v*2] + sum[v * 2 + 1]);
}
int get(int v, int l, int r, int dd){
	if(l == r) return l;
	int mid = (l + r)>>1;
	if(t[v * 2+1] + dd < 0) {
		return get(v * 2+1, mid+1, r, dd);
	}
	return get(v * 2, l, mid, dd + sum[v*2+1]);
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0;  i< n; i++){
		scanf("%d", &a[i]);
		add(1, 0, N, a[i], -1); 
	}
	
	for(int i = 0;  i< m; i++){
		scanf("%d", &b[i]);
		add(1, 0, N, b[i], 1);
	}
	scanf("%d", &q);
	for(int i=0; i < q; i++){
		int ty, ii, x;
		scanf("%d%d%d", &ty, &ii, &x);
		ii--;
		if(ty == 1) {
			add(1, 0, N, a[ii], +1);
			a[ii] = x;
			add(1, 0, N, a[ii], -1);
		}else{
			add(1, 0, N, b[ii], -1);
			b[ii] = x;
			add(1, 0, N, b[ii], +1);
		}
		if(t[1] >= 0) {
			printf("-1\n");
		}else {
			printf("%d\n", get(1, 0, N, 0));
		}
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