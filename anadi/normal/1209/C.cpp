#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
char in[N];
int color[N];

bool check(int d){
	d += '0';
	for(int i = 1; i <= n; ++i)
		color[i] = 2;

	bool can = true;
	for(int i = n; i >= 1; --i){
		if(in[i] < d){
			can = false;
			color[i] = 1;
		}
		
		if(in[i] > d)
			continue;
		
		if(can)
			color[i] = 1;
	}
	
	int last = '0';
	for(int i = 1; i <= n; ++i)
		if(color[i] == 1){
			if(in[i] < last)
				return false;
			last = in[i];
		}
	
	for(int i = 1; i <= n; ++i)
		if(color[i] == 2){
			if(in[i] < last)
				return false;
			last = in[i];
		}
		
	return true;
}

void solve(){
	scanf("%d", &n);
	scanf("%s", in + 1);
	
	int who = -1;
	for(int i = 0; i <= 9; ++i)
		if(check(i)){
			who = i;
			break;
		}
	
	if(who == -1)
		puts("-");
	else{
		for(int i = 1; i <= n; ++i)
			printf("%d", color[i]);
		puts("");
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}