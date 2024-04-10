#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second

const int inf = 1e9 + 7;

int n;
int mn[1007];
bool can[1007];
vector <int> quest;

void wypisz(){
	puts("-1");
	for(int i = 1; i <= n; ++i)
		printf("%d ", mn[i]);
	fflush(stdout);
}

void ask(){
	printf("%d\n", quest.size());
	for(auto v: quest)
		printf("%d ", v);
	fflush(stdout);
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		if(!can[i])
			mn[i] = min(mn[i], a);
	}
	
	quest.clear();
}

void pair_of_ask(int roz){
	for(int i = 1; i <= n; ++i)
		if(i%(2 * roz) < roz){
			can[i] = true;
			quest.pb(i);
		}
	
	ask();
	for(int i = 1; i <= n; ++i){
		if(!can[i])
			quest.pb(i);
		can[i] ^= 1;
	}
	
	ask();
	for(int i = 1; i <= n; ++i)
		can[i] = false;
}

void solve(){
	int questions = 1;
	while(questions < n)
		questions *= 2;
	questions /= 2;

	while(questions > 0){
		pair_of_ask(questions);
		questions /= 2;
	}
	
	wypisz();
}

int main(){
	scanf("%d", &n);	
	for(int i = 1; i <= n; ++i)
		mn[i] = inf;
	solve();
	return 0;
}