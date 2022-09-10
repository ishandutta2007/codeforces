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
int p[N][4];
int s[N][4];
int in[N][4];

int main(){
	scanf("%d", &n);
	p[0][0] = p[0][1] = -MX;
	p[0][2] = p[0][3] = MX;
	for(int i = 1; i <= n; ++i){
		scanf("%d %d %d %d", &in[i][0], &in[i][1], &in[i][2], &in[i][3]);
		p[i][0] = max(p[i - 1][0], in[i][0]);
		p[i][1] = max(p[i - 1][1], in[i][1]);
		p[i][2] = min(p[i - 1][2], in[i][2]);
		p[i][3] = min(p[i - 1][3], in[i][3]);		
	}
	
	s[n + 1][0] = s[n + 1][1] = -MX;
	s[n + 1][2] = s[n + 1][3] = MX;

	for(int i = n; i >= 1; --i){
		s[i][0] = max(s[i + 1][0], in[i][0]);
		s[i][1] = max(s[i + 1][1], in[i][1]);
		s[i][2] = min(s[i + 1][2], in[i][2]);
		s[i][3] = min(s[i + 1][3], in[i][3]);		
	}
	
	for(int i = 1; i <= n; ++i)
		if(max(p[i - 1][0], s[i + 1][0]) <= min(p[i - 1][2], s[i + 1][2]) && max(p[i - 1][1], s[i + 1][1]) <= min(p[i - 1][3], s[i + 1][3])){
			printf("%d %d\n", max(p[i - 1][0], s[i + 1][0]), max(p[i - 1][1], s[i + 1][1]));
			return 0;
		}

	return 0;
}