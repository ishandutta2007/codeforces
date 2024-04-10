#include <bits/stdc++.h>

using namespace std;

typedef double D;
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
char a[N], b[N];
vector <int> marks;

int main(){
	scanf("%d", &n);
	scanf("%s %s", a + 1, b + 1);
	
	int prv = -1, nxt = -1;
	for(int i = 1; i <= n; ++i)
		if(a[i] != b[i]){
			if(prv == -1)
				prv = i;
			nxt = i;
		}
	
	if(prv == nxt){
		puts("2");
		return 0;
	}
	
	bool oka = true, okb = true;
	for(int i = prv; i < nxt; ++i){
		oka &= a[i] == b[i + 1];
		okb &= a[i + 1] == b[i];
	}
	
	printf("%d\n", oka + okb);
	return 0;
}