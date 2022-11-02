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
int n, k, m;
int t[6000200];
int en = 1000100;
void add(int v, int l, int r, int pos){
	if(l == r){
		++t[v];
		return;
	}
	int mid = (l + r)>>1;
	if(pos <= mid){
		add(v * 2, l, mid, pos);
	}
	else {
		add(v*2+1,mid+1, r, pos);
	}
	t[v] = t[v*2]+t[v*2+1];
}
int addx(int v, int l, int r, int pos){
	if(t[v] == 0) return 0;
	if(l == r){
		--t[v];
		return 1;
	}
	int mid = (l + r)>>1;
	int was = 0;
	if(pos <= mid){
		was |= addx(v * 2, l, mid, pos);
	}
	else if(addx(v*2+1,mid+1, r, pos)){
		was = 1;
	}
	else {
		was |= addx(v * 2, l, mid, pos);
	}
	t[v] = t[v*2]+t[v*2+1];
	return was;
}
int get(int v, int l, int r, int x, int y){
	if(x > r || l > y) return 0;
	if(x <= l && r <= y){
		return t[v];
	}
	int mid = (l + r)>>1;
	return get(v * 2, l, mid, x, y) + get(v * 2 + 1, mid+1, r, x, y);
}
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		add(1, 0, en - 1, x);
	}
	int sum = 0;
	for(int i = m; i < en; i++){
		while(get(1, 0, en - 1, i-m+1, i) >= k){
			addx(1, 0, en-1, i);
			sum++;
		}
	}
	cout << sum<<endl;
	
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}