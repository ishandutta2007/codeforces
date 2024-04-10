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
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, q;
int Cord, Start, End;

PII wsp[N];
int pref[N];

double ask(double place){
	int p = 0, k = n;
	while(p < k){
		int m = (p + k + 1) / 2;
		if(wsp[m].nd <= place)
			p = m;
		else
			k = m - 1;
	}
	
	double ret = pref[p];
	p++;
	
	if(n < p || place < wsp[p].st)
		return ret;
	return ret + place - wsp[p].st;
}

void solve(){
	int x, y;
	scanf("%d %d", &x, &y);
	
	double From = x - double(x - Start) / double(y - Cord) * double(y);
	double To = x - double(x - End) / double(y - Cord) * double(y);
	
	double res = ask(To) - ask(From);
	res = res * double(y - Cord) / double(y);
	printf("%.9lf\n", res);
}

int main(){
	scanf("%d %d %d", &Cord, &Start, &End);
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &wsp[i].st, &wsp[i].nd);
		pref[i] = pref[i - 1] + wsp[i].nd - wsp[i].st;
	}
	
	scanf("%d", &q);
	while(q--)
		solve();
	return 0;
}