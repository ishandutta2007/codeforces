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
#include <cassert>

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

const int inf = (1ll << 25) - 1;
const int maxn = (int)3e6+100;
const int mod = (int) 1e9 + 7;
using namespace std;
struct node{
	map<char, int> nxt;
	int len;
	int link;
	int cnt;
	int mx;
} s[maxn];
int N;
int last = 0;
ll dp[maxn];
void init() {
	s[0].link = -1;
	s[0].len = 0;
	s[0].nxt.clear();
	N = 1;
	last = 0;
}
void add(char c) {
	int v = N;
	s[v].cnt = 1;
	N++;
	int p = last;
	s[v].nxt.clear();
	s[v].len = s[p].len + 1;
	while(p != -1 && !s[p].nxt.count(c)) {
		s[p].nxt[c] = v;
		p = s[p].link;
	}
	if(p == -1) {
		s[v].link = 0;
	} else {
		int q = s[p].nxt[c];
		if(s[q].len == s[p].len + 1) {
			s[v].link = q;
		} else {
			int cl = N++;
			s[cl].len = s[p].len + 1;
			s[cl].link = s[q].link;
			s[cl].nxt = s[q].nxt;
			while(p!=-1 && s[p].nxt[c] == q) {
				s[p].nxt[c] = cl;
				p = s[p].link;
			}
			s[v].link = s[q].link = cl;
		}
	}
	last = v;
}
int cmp(int i, int j){
	return s[i].len > s[j].len;
}
void calc() {
	vector<int> p;
	for(int i = 0; i < N; i++) p.pb(i);
	sort(all(p), cmp);
	for(int i = 0; i < p.size(); i++) {
		if(s[p[i]].link != -1) {
			s[s[p[i]].link].cnt += s[p[i]].cnt;
		}
	}

}
int u[maxn];
int T;
int get(string t) {
	T++;
	int v = 0;
	int ans = 0;
	int L = 0;
	for(int i = 0; i < t.size(); i++) {
		while(v && !s[v].nxt.count(t[i])) {
			v = s[v].link;
			L = s[v].len;
		}
		if(s[v].nxt.count(t[i])) {
			v = s[v].nxt[t[i]];
			L++;
		}
	}
	if(L == t.size()) {
		u[v] = T;
		ans += s[v].cnt;	
	}
	for(int i = 0; i < t.size(); i++) {
		if(L == t.size()){
			L--;
			if(s[s[v].link].len == L) {
				v = s[v].link;
			}
		}
		while(v && !s[v].nxt.count(t[i])) {
			v = s[v].link;
			L = s[v].len;
		}
		if(s[v].nxt.count(t[i])) {
			v = s[v].nxt[t[i]];
			L++;
		}
		if(L == t.size() && u[v] != T) {
			ans += s[v].cnt;
			u[v] = T;
		}
	}

	return ans;
}
void solve(){
	string t;
	cin >> t;
	init();
	for(int i = 0; i < t.size(); i++) add(t[i]);
	calc();
	int x;
	cin >> x;
	for(int i = 0; i < x; i++) {
		cin >> t;
		cout << get(t) << "\n";
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