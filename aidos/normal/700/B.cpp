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


int lev[200200];
int id[200200];
int used[200200];
vector<int> g[200200];
int a[200200];
map < int, int > m1[200200], m2[200200], temp1, temp2;
int n, k;
int sz = 1;
ll ans=0;
int cnt[200200];

void merge(int x, int y, int len){
	temp1.clear();
	if(m2[y].size() > 0 && m2[x].size() > 0){
		ans += (--m2[y].end())->f;
		ans += (--m2[x].end())->f;
		ans -= 2 * len;
		temp1[len]++;
		m2[x].clear();
		m2[y].clear();		
		cnt[x]++;
	}
	while(m1[y].size() + m2[y].size() > 0){
		if(m1[y].size() > 0){
			map<int, int> :: iterator it = m1[y].end();
			it--;
			map<int, int> :: iterator it2 = m1[x].end();
			it2--;
			ans += 2 * it->f;
			ans += 2 * it2->f;
			ans -= 4 * len;
			it->s--;
			if(it->s == 0){
				m1[y].erase(it);
			}
			it2->s--;
			if(it2->s == 0){
				m1[x].erase(it2);
			}
			temp1[len] += 2;
			cnt[x]++;
		}else {
			map<int, int> :: iterator it = m2[y].end();
			it--;
			map<int, int> :: iterator it2 = m1[x].end();
			it2--;
			ans += it->f;
			ans+=it2->f;
			ans -= 2 * len;
			m2[x][it2->f]++;
			it2->s--;
			if(it2->s == 0){
				m1[x].erase(it2);
			}
			temp1[len]++;
			m2[y].clear();
		}
	}
	for(map<int, int> :: iterator it = temp1.begin(); it != temp1.end(); it++){
		m1[x][it->f] += it->s;
	}
}
void dfs(int v, int le){
	lev[v] = le;
	id[v] = sz;
	sz++;
	if(a[v]) {
		m2[id[v]][le]++;
	}
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(used[to]) continue;
		dfs(to, le + 1);
		if(cnt[id[v]] * 2+ m2[id[v]].size()> cnt[id[to]] * 2+ m2[id[to]].size()){
			merge(id[v], id[to], le);
		}else {
			merge(id[to], id[v], le);
			id[v] = id[to];
		}
	}
}
void solve(){
	scanf("%d %d", &n, &k);
	for(int i = 0, x; i < 2 * k; i++){
		scanf("%d", &x);
		a[x] = 1;
	}
	for(int i = 1, x, y; i < n; i++){
		scanf("%d %d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	cout << ans << endl;
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