#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 107;

int n, m;
bool vis[N];
pair <int, PII> hero[N];

int glob;
bool cmp(pair <int, PII> a, pair <int, PII> b){
	if(abs(a.st - glob) != abs(b.st - glob))
		return abs(a.st - glob) > abs(b.st - glob);
	return a.st < b.st;
}

bool can(int from, int to, int hp, vector <int> &cur){
	int rm = from;
	int dir = from < to ? 1 : -1;

	while(from != to){
		from += dir;
		if(cur[from] + hp < 0)
			return false;

		hp += cur[from];
	}
	
	from = rm;
	while(from != to){
		from += dir;
		cur[from] = 0;
	}
	
	return true;
}

vector <int> solve(int t, vector <int> cur){
	for(int i = 1; i <= m; ++i)
		vis[i] = false;

	vector <int> ret;
	sort(hero + 1, hero + m + 1, cmp);
	
	while(true){
		bool ok = false;
		for(int i = 1; i <= m; ++i)
			if(!vis[i] && can(hero[i].st, t, hero[i].nd.st, cur)){
				ret.push_back(hero[i].nd.nd);
				vis[i] = true;
				ok = true;
				break;
			}
		
		if(!ok)
			break;
	}
	
	return ret;		
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &hero[i].st, &hero[i].nd.st);
		hero[i].nd.nd = i;
	}
	
	vector <int> ini(n + 1);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &ini[i]);
	
	for(int i = 1; i <= n; ++i){
		vector <int> ret = solve(i, ini);
		if(ret.size() == m){
			printf("%d\n", i);
			for(int v: ret)
				printf("%d ", v);
			return 0;
		}
	}
	
	puts("-1");
	return 0;
}