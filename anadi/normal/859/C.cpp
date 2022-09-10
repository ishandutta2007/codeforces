#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 3 * N + 9;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	int curS = 0, curB = 0;
	for(int i = n; i >= 1; --i){
		curB = max(curB, tab[i] + curS - curB);
		curS += tab[i];
	}

	printf("%d %d\n", curS - curB, curB);
	return 0;
}