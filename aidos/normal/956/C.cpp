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

using namespace std;
int t[4 * 100100];
int a[100100];
int get(int v, int l, int r, int tl, int tr){
	if(l > tr || r < tl) return -inf;
	if(tl <= l && r <= tr){
		return t[v];
	}
	int mid = (l + r)>>1;
	return max(get(v * 2, l, mid, tl, tr), get(v * 2 + 1, mid + 1, r, tl, tr));
}
void build(int v, int l, int r){
	if(l == r){
		t[v] = a[l] - l;
	}
	else{
		int mid=(l + r)>>1;
		build(v * 2, l, mid);
		build(v * 2 + 1, mid+1, r);
		t[v] = max(t[v* 2], t[v * 2 + 1]);	
	}
}
int n;
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int x = 1;
	build(1, 0, n-1);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(get(1, 0, n-1, i, n-1) == x - i) x++;
		ans += x - a[i] - 1;
	}
	cout << ans << endl;
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