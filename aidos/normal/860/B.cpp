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

int n;
string s[100100];
std::vector< map<int, int> > nxt;
std::vector< set<int> > S;
int sz = 1;
char tmp[444];

void add(string &x, int g, int v){
	int st = 0;
	for(int j = g; j < x.size(); j++){
		if(!nxt[st].count(x[j])){
			nxt[st][x[j]] = nxt.size();
			map<int, int> m;
			nxt.pb(m);
			S.pb(set<int>());
		}
		st = nxt[st][x[j]];
		S[st].insert(v);
	}
}

int get(string &x, int g){
	int st = 0;
	for(int j = g; j < x.size(); j++){
		st = nxt[st][x[j]];
		if(S[st].size() == 1) return j - g + 1;
	}
	return -1;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", tmp);
		s[i] = tmp;
	}
	map<int, int > m;
	nxt.pb(m);
	S.pb(set<int>());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s[i].size(); j++){
			add(s[i], j, i);
		}
	}
	for(int i = 0; i < n; i++){
		int len = inf;
		int st = -1;
		for(int j = 0; j<s[i].size(); j++){
			int g = get(s[i], j);
			if(g == -1) continue;
			if(len > g){
				st = j;
				len = g;
			}
		}
		for(int t = 0; t < len; t++){
			printf("%c", s[i][st + t]);
		}
		printf("\n");
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