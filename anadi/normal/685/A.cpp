#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>

const int mxn = 3e5 + 9;

LL n, m;
int result = 0;
int tab[30];
int t[30];
bool use[30];

LL change(LL a){
	LL res = 0LL;
	int licz = 0;
	while(a > 0LL){
		tab[++licz] = a%7LL;
		a /= 7LL;
	}

	while(licz > 0){
		res *= 10LL;
		res += tab[licz];
		--licz;
	}

	return res;
}

int cyf(LL a){
	int licz = 0;
	while(a > 0){
		a /= 10LL;
		licz++;
	}
	
	return max(licz, 1);
}

int liczba(int a, int b){
	int res = 0;
	for(int i = a; i <= b; ++i){
		res *= 10;
		res += t[i];
	}
	
	return res;
}

void zrob(int now, int to){
	if(now == to){
		if(liczba(1, cyf(n)) <= n && liczba(cyf(n) + 1, cyf(n) + cyf(m)) <= m)
			++result;
		return;
	}
	
	for(int i = 0; i < 7; ++i)
		if(!use[i]){
			t[++now] = i;
			use[i] = true;
			zrob(now, to);
			--now;
			use[i] = false;
		}
}

int main(){
	scanf("%I64d %I64d", &n, &m);
	n = change(n - 1);
	m = change(m - 1);
	int ile_cyfr = cyf(n) + cyf(m);
	if(ile_cyfr > 7){
		puts("0");
		return 0;
	}
	
	zrob(0, ile_cyfr);
	
	printf("%d\n", result);
	return 0;
}