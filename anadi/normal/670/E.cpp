#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 5e5 + 7;
const LL INF = 1e9 + 7LL;
const LL MX = 2e9;

int n, m, p;
int next[mxn];
int prev[mxn];
char s[mxn];
char inst[mxn];

int usun(int pos){
	int ile = 1;
	int x = pos;
	while(ile > 0){
		x = next[x];
		if(s[x] == ')')
			--ile;
		else
			++ile;
	}
	
	prev[next[x]] = prev[pos];
	next[prev[pos]] = next[x];
	if(next[x] <= n)
		return next[x];
	else
		return prev[pos];
}

int usun2(int pos){
	int ile = 1;
	int x = pos;
	while(ile > 0){
		x = prev[x];
		if(s[x] == ')')
			++ile;
		else
			--ile;
	}
	
	next[prev[x]] = next[pos];
	prev[next[pos]] = prev[x];
	if(next[pos] <= n)
		return next[pos];
	else
		return prev[x];
}

int main(){
	scanf("%d %d %d", &n, &m, &p);
	scanf("%s", s + 1);
	scanf("%s", inst + 1);
	
	for(int i = 0; i <= n + 1; ++i){
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	
	int now = p;
	for(int i = 1; i <= m; ++i){
		if(inst[i] == 'L'){
			now = prev[now];
			continue;
		}
		if(inst[i] == 'R'){
			now = next[now];
			continue;
		}
		if(s[now] == '(')
			now = usun(now);
		else
			now = usun2(now);
	}
	
	now = 0;
	while(next[now] <= n){
		now = next[now];
		printf("%c", s[now]);
	}
	return 0;
}