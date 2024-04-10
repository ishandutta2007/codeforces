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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
struct node{
	int pref, suff, sum;
	
} t[4*maxn];
string s;
int n;

node merge(node a, node b) {
	node c;
	int x = min(a.suff, b.pref);
	c.sum = a.sum + b.sum + 2*x;
	c.pref = a.pref + b.pref-x;
	c.suff = a.suff - x + b.suff;
	return c;
}

node get(int v, int tl, int tr, int l, int r) {
	if(tl > r || tr < l) return {0, 0, 0};
	if(l <= tl && tr <= r) return t[v];
	int mid = (tl+tr)>>1;
	return merge(get(v*2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}

void build(int v, int l, int r) {
	if(l == r) {
		if(s[l] == '(') t[v] = {0, 1, 0};
		else t[v] = {1, 0, 0};
	}else {
		int mid = (l + r)>>1;
		build(v*2, l, mid);
		build(v*2+1, mid+1, r);
		t[v] = merge(t[v*2], t[v*2+1]);
	}
}
void solve(){
	cin >> s;
	n = s.size();
	build(1, 0, n-1);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		cout << get(1, 0, n-1, l-1, r-1).sum << "\n";
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