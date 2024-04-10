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


int t[4000400];
int a[1000100];
vector<int> g[1000100];
int n, m;
int l[1000100];
int r[1000100];
int sum[1000100];
int ans[1000100];

void add(int pos, int val){
	while(pos <= n){
		t[pos] ^= val;
		pos |= pos+1;
	}
}
int get(int pos){
	int res=  0;
	while(pos >= 0){
		res ^= t[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] ^ a[i];
	}
	map<int, int> mm;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l[i], &r[i]);
		g[r[i]].pb(i);
	}
	
	for(int i = 1; i <= n; i++){
		if(mm.count(a[i]))
			add(mm[a[i]], a[i]);
		mm[a[i]] = i;
		add(i, a[i]);
		for(int j = 0; j < g[i].size(); j++){
			int id = g[i][j];
			int ind = l[id];
			ans[id] = sum[i] ^ sum[ind - 1] ^ get(ind-1) ^ get(i);
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}