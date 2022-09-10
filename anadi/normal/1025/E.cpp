#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 57;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int place[N];
pair <PII, int> s[N];
pair <PII, int> e[N];
vector <pair <PII, PII> > res;


void go(int idx, int dx, int dy){
	res.push_back({s[idx].st, {s[idx].st.st + dx, s[idx].st.nd + dy}});
	s[idx].st.st += dx, s[idx].st.nd += dy;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &s[i].st.st, &s[i].st.nd);
		s[i].nd = i;
	}
	
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &e[i].st.st, &e[i].st.nd);
		e[i].nd = i;
	}	
	
	sort(s + 1, s + m + 1);
	for(int i = 1; i <= m; ++i)
		while(s[i].st.st > i)
			go(i, -1, 0);
	
	for(int i = m; i >= 1; --i)
		while(s[i].st.st < i)
			go(i, 1, 0);
	
	for(int i = 1; i <= m; ++i){
		place[s[i].nd] = i;
		assert(s[i].st.st == i);
	}

	sort(e + 1, e + m + 1, [](pair <PII, int> a, pair <PII, int> b){return a.st.nd < b.st.nd;});
	
	for(int i = 1; i <= m; ++i){
		int idx = place[e[i].nd];
		while(s[idx].st.nd < i)
			go(idx, 0, 1);
		while(i < s[idx].st.nd)
			go(idx, 0, -1);
		assert(s[idx].st.nd == i);
	}

	for(int i = 1; i <= m; ++i){
		int idx = place[e[i].nd];
		while(s[idx].st.st < e[i].st.st)
			go(idx, 1, 0);
		while(e[i].st.st < s[idx].st.st)
			go(idx, -1, 0);
	}
	
	for(int i = 1; i <= m; ++i){
		int idx = place[e[i].nd];
		while(e[i].st.nd < s[idx].st.nd)
			go(idx, 0, -1);
	}
	
	for(int i = m; i >= 1; --i){
		int idx = place[e[i].nd];
		while(s[idx].st.nd < e[i].st.nd)
			go(idx, 0, 1);
	}
	
	printf("%d\n", res.size());
	for(auto v: res)
		printf("%d %d %d %d\n", v.st.st, v.st.nd, v.nd.st, v.nd.nd);
	return 0;
}