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

int fast(int a, int b){
	if(b == 0)
		return 1;
	int x = fast(a, b / 2);
	
	if(b & 1)
		return (((1LL * x * x)%MX) * a)%MX;
	return (1LL * x * x)%MX;
}

int n, m;
int odw, odw2;
int s[N][2];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &s[i][0]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &s[i][1]);

	odw = fast(m, MX - 2);
	odw2 = fast(2, MX - 2);
	
	int cur = 1, res = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i][0] == 0 && s[i][1] == 0){
			res += (((((1LL * cur * (m - 1))%MX) * odw)%MX) * odw2)%MX; res %= MX;
			cur = (1LL * cur * odw)%MX;
			continue;
		}
		
		if(s[i][0] == 0){
			res += (((1LL * cur * (m - s[i][1]))%MX) * odw)%MX; res %= MX;
			cur = (1LL * cur * odw)%MX;
			continue;
		}
		
		if(s[i][1] == 0){
			res += (((1LL * cur * (s[i][0] - 1))%MX) * odw)%MX; res %= MX;
			cur = (1LL * cur * odw)%MX;
			continue;
		}
		
		if(s[i][0] > s[i][1]){
			res += cur; res %= MX;
			break;
		}
		
		if(s[i][0] < s[i][1]){
			cur = 0;
			continue;
		}
	}

	printf("%d\n", res);
	return 0;
}