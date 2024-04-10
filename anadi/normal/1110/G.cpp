#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
char s[N];
vector <int> G[N];

bool check(){
	int cnt1 = 0, cnt3 = 0;
	for(int i = 1; i <= n; ++i){
		if(G[i].size() > 3)
			return false;
		
		cnt1 += G[i].size() == 1;
		cnt3 += G[i].size() == 3;
	}
	
	if(cnt3 > 2)
		return false;
	if(cnt1 > 4)
		return false;
	
	for(int i = 1; i <= n; ++i)
		if(G[i].size() > 1 && s[i] == 'W')
			return false;

	for(int i = 1; i <= n; ++i)
		if(G[i].size() == 3){
			int cnt2 = 0;
			for(int v: G[i])
				if(G[v].size() > 1)
					cnt2++;
			
			if(cnt2 > 1)
				return false;
			
			int cntW = 0;
			for(int v: G[i])
				if(s[v] == 'W')
					++cntW;
			
			if(cntW >= 1)
				return false;
		}
	
	if(cnt3 == 2)
		return n%2 == 0;
	
	if(cnt3 == 1){
		int cntW = 0;
		for(int i = 1; i <= n; ++i)
			cntW += s[i] == 'W';
		
		if(cntW == 0)
			return true;
		return n%2 == 1;
	}

	for(int i = 1; i <= n; ++i)
		if(G[i].size() == 1 && s[i] != 'W')
			return true;

	return n%2 == 0;
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		G[i].clear();
	
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		G[v].push_back(u);
	}

	scanf("%s", s + 1);	
	if(n < 3){
		puts("Draw");
		return;
	}
	
	if(n == 3){
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			cnt += s[i] == 'W';
		
		if(cnt == 2)
			puts("White");
		else
			puts("Draw");
		return;
	}
	
	if(!check()){
		puts("White");
		return;
	}
	
	puts("Draw");
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}