#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;


int dp[2050][2500][5];
struct state {
	int len, link;
	map<char,int> next;
};
state st[5050];
int sz, last;
void sa_init() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
}
void sa_extend (char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

string cur;


int d;
int get(int pos, int len, int t){
	if((len / 51) == d) return t % 2;
	int &res = dp[pos][len][t];
	if(res != -1) return res;
	res = 0;
	if((t/2)){
		int poss = len/51;
		for(int i = '0'; i <= cur[poss]; i++){
			int lenx = len % 51;
			int nxt = pos;
			while(nxt && !st[nxt].next.count(i)) {	
				nxt = st[nxt].link;
				lenx = st[nxt].len;
			}
			if(st[nxt].next.count(i) ) {
				nxt = st[nxt].next[i];
				lenx++;
			}
			int tt = (lenx >= (d/2)) || t % 2;
			res += get(nxt, (len/51 + 1) * 51 + lenx, (i == cur[poss]) * 2 + tt);
			if(res >= mod) res -= mod;
		}	
	}
	else {

		for(int i = '0'; i <= '9'; i++){
			int lenx = len % 51;
			int nxt = pos;
			while(nxt && !st[nxt].next.count(i)) {	
				nxt = st[nxt].link;
				lenx = st[nxt].len;
			}
			if(st[nxt].next.count(i) ) {
				nxt = st[nxt].next[i];
				lenx++;
			}
			int tt = (lenx >= (d/2)) || t % 2;
			res += get(nxt, (len/51 + 1) * 51 + lenx, tt);
			if(res >= mod) res -= mod;
		}
	}
	return res;
}
int calc(string a){
	cur = a;
	memset(dp, -1, sizeof dp);
	d = a.size();
	return get(0, 0, 2);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    string s;
	cin >> s;
	sa_init();
	for(int i = 0; i < s.size(); i++)
		sa_extend(s[i]);
	string a, b;
	cin >> a >> b;
	bool ok = 0;
	for(int  i = 0; i < a.size(); i++){
		if(a[i] >'0')ok=1;
	}
	int ans = calc(b);
	if(ok){
		a[a.size() - 1]--;
		for(int i =0; i < a.size(); i++){
			if(a[i] < '0') {
				a[i] += 10;
				a[i + 1]--;
			}
			else break;
		}
		ans -= calc(a);
		if(ans < mod) ans += mod;
		if(ans >= mod) ans -= mod;
	}
	printf("%d\n", ans);



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}