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
int t[400400];
int n, m;
int ans;
int la[400400];
vector< pair<int, pii> > g[100100];
int cnt[44][44];
vector<pii> temp;
int cur = 0;
void clr(){
	ans = 0;
	cur = 0;
	for(int i = 0; i < 44; i++)
		for(int j = 0; j < 44; j++)
			cnt[i][j] = 0;
}
void add(pii x){
	cnt[x.f][x.s]++;
	cur++;
}
void del(pii x){
	cnt[x.f][x.s]--;
	cur--;
}

bool isgood(){
	temp.clear();
	for(int i = 1; i < 41; i++){
		for(int j = 0; j < i; j++){
			if(cnt[j][i]>0){
				int k = i;
				for(int t= 2; t < 41; t++){
					if(k % t == 0){
						int cc = 1;
						while(k % t == 0){
							cc *= t;						
							temp.pb(mp(cc, j % cc));
							k/=t;
						}
					}
				}
			}
		}
	}
	sort(all(temp));
	for(int i = 1; i < temp.size(); i++)
		if(temp[i].f == temp[i-1].f && temp[i].s != temp[i-1].s) return 0;
	return 1;
}
void get(vector<pair<int, pii > > &v){
	clr();
	if(v.size() == 0) return;
	for(int i = 0, j = 0; i < v.size(); ){
		if(i == j) {
			add(v[i].s);
			j++;
		}
		while(j < v.size()){
			if(v[j].f - 1 != v[j-1].f) break;
			add(v[j].s);
			if(isgood()){
				j++;
			}else {
				del(v[j].s);
				break;
			}
		}
		ans = max(ans, cur);
		del(v[i].s);
		i++;
	}

}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0, k; i < n; i++){
		scanf("%d", &k);
		for(int j = 0, x; j < k; j++){
			scanf("%d", &x);
			g[x].pb(mp(i, mp(j, k)));
		}
	}
	for(int i = 1; i <= m; i++){		
		get(g[i]);
		printf("%d\n", ans);
	}
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