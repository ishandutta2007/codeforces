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

const int inf = (1 << 29) - 1;
const int maxn = (int)2e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int nxt[maxn][26];
int P[maxn][26];
int link[maxn];
int sz = 0;
int en[maxn];
int d[maxn];
int n;
string s[maxn];
string t;
vector<int> calc() {
	vector<int> ans;
	memset(nxt, 0, sizeof nxt);
	memset(en, 0, sizeof en);
	sz = 1;
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(int j = 0; j < s[i].size(); j++) {
			int c = s[i][j] - 'a';
			if(nxt[cur][c] == 0) nxt[cur][c] = sz++;
			cur = nxt[cur][c];
		}
		en[cur]++;
	}
	queue <int> q;
	link[0] = -1;
	q.push(0);
	while(q.size()) {
		int v = q.front();
		q.pop();
		for(int c = 0; c < 26; c++) {
			int to = nxt[v][c];
			if(to == 0) continue;
			q.push(to);
			if(link[v] == -1) {
				link[to] = 0;
			}
			else {
				link[to] = P[link[v]][c];
			}
		}
		if(link[v] == -1) {
			for(int i = 0; i < 26; i++) P[0][i] = nxt[0][i];
		} else {
			for(int i = 0; i < 26; i++) {
				if(nxt[v][i])
					P[v][i] = nxt[v][i];
				else
					P[v][i] = P[link[v]][i];
			}
			d[v] = d[link[v]] + en[v];
		}
	}

	int cur = 0;
	for(int i = 0; i < t.size(); i++) {
		int c = t[i] - 'a';
		cur = P[cur][c];
		ans.pb(d[cur]);
	}

	return ans;
}
void solve(){
	cin >> t >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<int> l = calc();
	reverse(all(t));
	for(int i = 0; i < n; i++) reverse(all(s[i]));
	vector<int> r = calc();
	reverse(all(r));
	ll ans = 0;
	for(int i = 1; i < l.size(); i++) ans += l[i-1] * 1ll*r[i];
	cout << ans << "\n";
}
int main () {
	int t = 1;
    //scanf("%d", &t);
    for(int i=1; i<=t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}