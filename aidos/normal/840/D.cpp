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

typedef vector<int> vi;
vector<int> t[4*300100];
vector<int> g[300300];
int q;
int n;

int ans[300300];
vector<int> qu[30];
int K;
int a[300300];	
int getCnt(int x, int l, int r){

	int R = upper_bound(all(g[x]), r)-g[x].begin();
	R--;
	int L = lower_bound(all(g[x]), l) - g[x].begin();
	return R - L + 1;
}

void build(int v, int l, int r){
	t[v].clear();
	if(l == r){
		t[v].pb(a[l]);
		return;
	}
	int mid = (l + r)>>1;
	build(v*2, l, mid);
	build(v*2+1, mid+1, r);
	for(int i = 0; i < t[v*2].size(); i++){
		if(getCnt(t[v*2][i], l, r) * 5 > r - l + 1){
			t[v].pb(t[v*2][i]);
		}
	}
	for(int i = 0; i < t[v*2+1].size(); i++){
		if(getCnt(t[v*2+1][i],l,r) * 5 > r - l + 1){
			t[v].pb(t[v*2+1][i]);
		}
	}
	sort(all(t[v]));
	t[v].resize(unique(all(t[v]))-t[v].begin());
}



void get(int v, int l, int r, int tl, int tr, vi &ansx){
	if(tl > tr) return;
	if(l == tl && r == tr){
		for(int i = 0; i < t[v].size(); i++)
			ansx.pb(t[v][i]);
		return;
	}
	int mid = (l+r)>>1;
	get(v*2, l, mid, tl, min(tr, mid), ansx);
	get(v*2+1, mid+1, r, max(tl, mid+1), tr, ansx);

}

int L[300300], R[300300];

int getV(vi &a, int l, int r, int k){
	int ans = -1;
	for(int i = 0; i < a.size(); i++){
		if(i > 0 && a[i] == a[i-1])	continue;	
	    if(getCnt(a[i], l, r) * k > (r-l+1) && (ans == -1 || ans > a[i])) ans = a[i];
	}
	return ans;
}

int readInt(){
	register int n  = 0;
	register char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	while(!(c == ' ' || c == '\n'|| c==EOF)){
		n = n * 10 + c - '0';
		c = getchar();
	}
	return n;
}

void solve(){
	n = readInt();
	q = readInt();
	for(int i = 0; i < n; i++){
		a[i]=readInt();
		g[a[i]].pb(i);
	}

	for(int i = 0, k; i < q; i++){
		L[i] = readInt();
		R[i] = readInt();
		k = readInt();
		R[i]--;
		L[i]--;
		qu[k].pb(i);
	}
	build(1, 0, n-1);
	for(int i = 2; i <= 5; i++){
		K = i * 2;
		vi ansx;
		for(int j = 0; j < qu[i].size(); j++){
			int ind = qu[i][j];
			ansx.clear();
			get(1, 0, n-1, L[ind], R[ind],ansx);
			sort(all(ansx));
			ans[ind] = getV(ansx, L[ind], R[ind], i);
		}
	}
	for(int i = 0; i < q; i++){
		printf("%d\n", ans[i]);
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}