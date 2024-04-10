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

char c[200200];
int p[200200];
vector<int> g[2];
int used[200200];
void solve(){
	scanf("%s", c);
	int n = strlen(c);
	for(int i = 0; i < n; i++){
		if(c[i] == '1'){
			if(g[0].size() == 0){
				printf("-1");
				return;
			}
			int pos = g[0].back();
			g[0].pop_back();
			p[i] = pos;
			g[1].pb(i);
		}else{
			if(g[1].size()>0){
				int pos = g[1].back();
				g[1].pop_back();
				p[i] = pos;
				g[0].pb(i);
			}else{
				p[i] = -1;
				g[0].pb(i);
			}
		}
	}
	if(g[1].size()){
		printf("-1");
		return;
	}
	vector< vector<int> >ans;
	for(int i = n-1; i >= 0; i--){
		if(used[i]) continue;
		int j = i;
		vector<int> c;
		while(j != -1){
			used[j] = 1;
			c.pb(j+1);
			j = p[j];
		}
		reverse(all(c));
		ans.pb(c);
	}
	printf("%d\n", (int)ans.size());
	forit(it, ans){
		vector<int>d = *it;
		printf("%d", (int)d.size());
		forit(it2, d){
			printf(" %d", *it2);
		}
		printf("\n");
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