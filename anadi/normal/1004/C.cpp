#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
int res[N];
int place[N];
set <int> S;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = n; i >= 1; --i){
		res[i] = S.size();
		S.insert(in[i]);
		place[in[i]] = i;
	}
	
	long long int result = 0LL;
	for(int i = 1; i < N; ++i){
		if(place[i] == 0)
			continue;
		
		result += res[place[i]];
	}
	
	printf("%lld\n", result);
	return 0;
}