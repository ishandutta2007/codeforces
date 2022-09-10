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
const LL INF = 1e18 + 19LL;

int q;
int tab[N];
LL cur = 0LL;

int main(){
	scanf("%d", &q);
	int wsk = 0, cnt = 0;
	while(q--){
		int t;
		scanf("%d", &t);
		
		if(t == 1){
			int a;
			scanf("%d", &a);
			tab[++cnt] = a;
		}
		else{
			while(wsk < cnt - 1 && D(cur + tab[wsk + 1] + tab[cnt]) / D(wsk + 2) < D(cur + tab[cnt]) / D(wsk + 1)){
				++wsk;
				cur += tab[wsk];
			}
			
			printf("%.9lf\n", tab[cnt] - D(cur + tab[cnt]) / D(wsk + 1));
		}
	}

	return 0;
}