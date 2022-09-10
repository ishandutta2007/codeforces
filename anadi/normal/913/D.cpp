#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, T;
set <PII> S;
pair <PII, int> tab[N];

int main(){
	scanf("%d %d", &n, &T);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &tab[i].st.st, &tab[i].st.nd);
		tab[i].nd = i;
	}
	
	int best = 0;
	sort(tab + 1, tab + n + 1);
	
	int curT = 0;
	for(int i = n; i >= 1; --i){
		curT += tab[i].st.nd;
		S.insert({tab[i].st.nd, tab[i].nd});

		while(S.size() > tab[i].st.st){
			auto it = S.end(); --it;
			curT -= (*it).st;
			S.erase(it);
		}
		
		while(curT > T){
			auto it = S.end(); --it;
			curT -= (*it).st;
			S.erase(it);
		}
		
		if(S.size() > best)
			best = S.size();
	}
	
	int cur = 0;
	printf("%d\n%d\n", best, best);
	
	sort(tab + 1, tab + n + 1, [](auto a, auto b) -> bool{if(a.st.nd == b.st.nd) return a.nd < b.nd; return a.st.nd < b.st.nd;});
	for(int i = 1; i <= n; ++i)
		if(cur < best && tab[i].st.st >= best){
			printf("%d ", tab[i].nd);
			++cur;
		}
	
	return 0;
}