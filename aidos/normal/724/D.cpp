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
char c[100100];
int n, m;
int used[100100];
int cnt[100100];
int nused[100100];
int dis[100100];

char temp[100100];
void solve(){
	scanf("%d%s", &m, c);
	n = strlen(c);
	vector<int>ans;
	for(int i = 0; i < n; i++){
		cnt[c[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(cnt[i] == 0) continue;
		for(int j = 0; j < n; j++)
			nused[j] = used[j];
		for(int j = 0; j < n; j++){
			if(c[j] - 'a' == i) used[j] = 1;
			dis[j] = inf;
		}
		int ind = -1;
		for(int j = 0; j < n; j++){
			if(used[j]) ind = j;
			if(ind != -1) dis[j] = j - ind;
		}
		bool bad = 0;
		for(int j = m-1; j < n; j++){
			if(dis[j] >= m) bad = 1;
		}
		if(!bad){
			for(int j = 0; j < n; j++)
				used[j] = nused[j];
			int ind = -1;
			int ind2 = -1;
			for(int j = 0; j < m-1; j++){
				if(used[j]) ind = j;
				if(c[j] - 'a' == i) ind2 = j;
			}
			for(int j = m-1; j < n; j++){
				if(used[j]) ind = j;
				if(c[j] - 'a'==i) ind2 = j;
				if(ind == -1 || j - ind >= m){
					ans.pb(i);
					ind = ind2;
				}
			}
			break;
		}
		else {
			for(int j = 0; j < cnt[i]; j++)
				ans.pb(i);
		}
	}
	for(int i = 0; i < ans.size(); i++){
		temp[i] = ans[i] + 'a';
	}
	temp[ans.size()] = 0;
	printf("%s\n", temp);
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