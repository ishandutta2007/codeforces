#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
char s[N];
int cnt[N];

int res;
int x[N], y[N];

bool used[N];
queue <int> Q;
bitset <N> B[N];

void add(int u, int v){
	x[++res] = u;
	y[res] = v;
//	printf("%d %d\n", u, v);
}

int get(int u){
	for(int i = 1; i <= n; ++i)
		if(!used[i] && i != u && ((B[i] & B[u]) == B[u]))
			return i;
	return -1;
}

void go(int t){
	for(int i = 1;  i <= n; ++i)
		if(!used[i] && B[i][t] == 1){
			B[i][t] = 0;

			int id = get(i);
			if(id == -1)
				return;

			used[i] = true;
			add(i, id);
			Q.push(i);
		}
}

void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%s", s + 1);
		for(int j = 1; j <= n; ++j){
			B[j][i] = s[j] - '0';
			cnt[i] += s[j] - '0';
		}
	}
	
	for(int i = 0; i < m; ++i)
		if(cnt[i] == 1)
			go(i);
	
	for(int i = 1; i <= n; ++i){
		if(used[i])
			continue;

		int id = get(i);
		if(id == -1)
			continue;

		add(i, id);
		Q.push(i);
		used[i] = true;
	}
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(int i = 0; i < m; ++i)
			if(B[u][i]){
				cnt[i]--;
				if(cnt[i] == 1)
					go(i);
			}
	}
	
	if(res == n - 1){
		puts("YES");
		for(int i = 1; i < n; ++i)
			printf("%d %d\n", x[i], y[i]);
	}
	else
		puts("NO");
	
	res = 0;
	for(int i = 1; i <= n; ++i)
		used[i] = false;
	for(int j = 0; j < m; ++j)
		cnt[j] = 0;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < m; ++j)
			B[i][j] = 0;
}

int main(){
	int quest;
	scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}