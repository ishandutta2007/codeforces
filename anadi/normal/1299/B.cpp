#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
PII in[N];

void no(){
	puts("NO");
	exit(0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &in[i].st, &in[i].nd);
	
	if(n & 1)
		no();
	
	set <int> all_x, all_y;
	for(int i = 1; i + i <= n; ++i){
		int nxt = i + n / 2;
		int sx = in[i].st + in[nxt].st;
		int sy = in[i].nd + in[nxt].nd;
		
		all_x.insert(sx);
		all_y.insert(sy);
	}
	
	if(all_x.size() == 1 && all_y.size() == 1)
		puts("YES");
	else
		no();
	return 0;
}