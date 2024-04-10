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
int cnt[15 * N];
bool marked[15 * N];

int nwd(int a, int b){
	int c;
	while(b){
		c = b;
		b = a%b;
		a = c;
	}
	
	return a;
}

int main(){
	scanf("%d", &n); 
	int mn = MX, mx = 0, d = 0;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);

		cnt[a]++;
		d = nwd(d, a);
		mn = min(mn, a), mx = max(mx, a);
	}
	
	if(mn == mx){
		puts("-1");
		return 0;
	}
	
	int res = n - 1;
	for(int i = d + d; i < 15 * N; i += d){
		if(!marked[i]){
			for(int j = i + i; j < 15 * N; j += i){
				cnt[i] += cnt[j];
				marked[j] = true;
			}

			res = min(res, n - cnt[i]);
		}
	}
	
	printf("%d\n", res);
	return 0;
}