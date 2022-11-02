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
char temp[100100], re[25];
int nxt[2000200][5];

int cnt[2000200];
int sz = 1;
void add(string &s, int ad){
	
	int v = 0;
	for(int i = 0; i < s.size(); i++){
		if(nxt[v][s[i] - '0'] == 0) {
			nxt[v][s[i] - '0'] = sz++;
		}
		v = nxt[v][s[i] - '0'];
	}
	cnt[v] += ad;
}

int get(string &s){
	int v = 0;
	for(int i = 0; i < s.size(); i++){
		if(nxt[v][s[i] - '0'] == 0) return 0;
		v = nxt[v][s[i] - '0'];
	}
	return cnt[v];
}
string t;
void solve(){
	scanf("%s%s", re, temp);
	int len = strlen(temp);
	reverse(temp, temp + len);
	t = temp;
	while(t.size() < 18) t += '0';
	for(int i = 0; i < t.size(); i++){
		if((t[i] - '0') & 1) t[i] = '1';
		else t[i] = '0';
	}
	if(re[0] == '+') add(t, 1);
	else if(re[0] == '-') add(t, -1);
	else{
		printf("%d\n", get(t));
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}