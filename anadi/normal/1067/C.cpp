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

const int DX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n;
int cnt = 0;
void ini(int x, int y){
	++cnt;
	printf("%d %d\n", x, y);
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		puts("0 0");
		return 0;
	}

	int t = (n + 6) / 6;
	for(int i = 0; i < t; ++i){
		ini(2 * i, 0);
		if(i > 0)
			ini(0, 2 * i);
		else
			ini(0, 2 * t);
	}

	t--;
	for(int i = 0; i < t; ++i){
		ini(2 * i + 1, 1);
		if(i > 0)
			ini(1, 2 * i + 1);
		else
			ini(1, 2 * t + 1);
	}

	t--;
	for(int i = 0; i < t; ++i){
		ini(2 * i + 2, 2);
		if(i > 0)
			ini(2, 2 * i + 2);
		else
			ini(2, 2 * t + 2);
	}

	t += 2;
	if(cnt < n)
		ini(2 * t - 1, 1);
	if(cnt < n)
		ini(2 * t, 0);
	if(cnt < n)
		ini(2 * t - 2, 2);
	if(cnt < n)
		ini(2 * t, 2);
	if(cnt < n)
		ini(2 * t - 1, 3);
	assert(cnt == n);
	return 0;
}