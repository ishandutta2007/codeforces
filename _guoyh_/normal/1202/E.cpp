# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct ACAM{
	struct Node{
		int nm;
		int fail;
		int nxt[26];
	} t[MAXN];
	int rt0, rt1, tsz;
	ACAM(){
		tsz = 0;
		rt0 = ++tsz;
		rt1 = ++tsz;
		for (int i = 0; i < 26; i++) t[rt0].nxt[i] = rt1;
		t[rt0].fail = t[rt1].fail = rt0;
	}
	void insert(char s[], int sz){
		int p = rt1;
		for (int i = 1; i <= sz; i++){
			if (!t[p].nxt[s[i] - 'a']) t[p].nxt[s[i] - 'a'] = ++tsz;
			p = t[p].nxt[s[i] - 'a'];
		}
		t[p].nm++;
	}
	void getfail(){
		queue <int> q;
		q.push(rt1);
		while (!q.empty()){
			int nw = q.front();
			q.pop();
			for (int i = 0; i < 26; i++){
				if (!t[nw].nxt[i]) t[nw].nxt[i] = t[t[nw].fail].nxt[i];
				else {
					t[t[nw].nxt[i]].fail = t[t[nw].fail].nxt[i];
					t[t[nw].nxt[i]].nm += t[t[t[nw].nxt[i]].fail].nm;
					q.push(t[nw].nxt[i]);
				}
			}
		}
	}
} t1, t2;
int n;
char s0[MAXN];
char s[MAXN];
int f1[MAXN], f2[MAXN];
int main(){
	scanf("%s", s0 + 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", s + 1);
		int sz = strlen(s + 1);
		t1.insert(s, sz);
		for (int j = 1; j < sz - j + 1; j++) swap(s[j], s[sz - j + 1]);
		t2.insert(s, sz);
	}
	t1.getfail();
	t2.getfail();
	int sz = strlen(s0 + 1);
	int p = t1.rt1;
	for (int i = 1; i <= sz; i++){
		p = t1.t[p].nxt[s0[i] - 'a'];
		f1[i] = t1.t[p].nm;
	}
	p = t2.rt1;
	for (int i = sz; i >= 1; i--){
		p = t2.t[p].nxt[s0[i] - 'a'];
		f2[i] = t2.t[p].nm;
	}
	ll ans = 0;
	for (int i = 1; i <= sz; i++) ans += 1ll * f1[i] * f2[i + 1];
	printf("%lld\n", ans);
	return 0;
}