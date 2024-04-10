#include <bits/stdc++.h>

using namespace std;

const int M = 105;
const int N = 1e6 + 7;
const long long int mx = 1e9 + 7;

int n, l, m;
int przed[N];
int beg[N], kon[N];

int help[M];
int mod[10 * M];
int cur[M], ile[M];

void mnoz(){
	for(int i = 0; i < m; ++i)
		help[i] = 0;

	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			help[i] = (help[i] + 1LL * cur[j] * cur[mod[i - j + m]])%mx;

	for(int i = 0; i < m; ++i)
		cur[i] = help[i];
}

void mnoz1(){
	for(int i = 0; i < m; ++i)
		help[i] = 0;

	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			help[i] = (help[i] + 1LL * cur[j] * ile[mod[i - j + m]])%mx;

	for(int i = 0; i < m; ++i)
		cur[i] = help[i];
}

void fast(int pot){
	if(pot == 1)
		return;
	
	fast(pot / 2);
	mnoz();
	if(pot & 1)
		mnoz1();
}

int main(){
	scanf("%d %d %d", &n, &l, &m);
	for(int i = 1; i < 10 * M; ++i)
		mod[i] = i%m;
	
	for(int i = 1; i <= n; ++i){
		int a; scanf("%d", &a);
		a %= m;
		beg[a]++;
	}

	for(int i = 1; i <= n; ++i){
		int a; scanf("%d", &a);
		a %= m;

		przed[i] = a;
		ile[a]++;
	}
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &kon[i]);
		kon[i] += przed[i];
		kon[i] %= m;
	}
	
	if(l == 2){
		for(int i = 1; i <= n; ++i)
			cur[kon[i]]++;
	
		int res = 0;
		for(int i = 0; i < m; ++i)
			res = (res + 1LL * beg[i] * cur[mod[m - i]])%mx;
		printf("%d\n", res);
		return 0;
	}
	
	for(int i = 0; i < m; ++i)
		cur[i] = ile[i];
	fast(l - 2);
	
	for(int i = 0; i < m; ++i)
		help[i] = 0;
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			help[i] = (help[i] + 1LL * cur[j] * beg[mod[i - j + m]])%mx;

	for(int i = 0; i < m; ++i)
		cur[i] = help[i];
	
	for(int i = 0; i < m; ++i)
		beg[i] = 0, help[i] = 0;

	for(int i = 1; i <= n; ++i)
		beg[kon[i]]++;
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			help[i] = (help[i] + 1LL * cur[j] * beg[mod[i - j + m]])%mx;

	for(int i = 0; i < m; ++i)
		cur[i] = help[i];
	printf("%d\n", cur[0]);
	return 0;
}