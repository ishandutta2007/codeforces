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
LL pot[70];
vector <LL> res;
vector <LL> V[70];

int bit(LL a){
	int t = 0;
	while(a){
		++t;
		a /= 2LL;
	}
	
	return t;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%lld", &a);
		V[bit(a)].push_back(a);
	}
	
	pot[1] = 1LL;
	for(int i = 2; i <= 60; ++i)
		pot[i] = pot[i - 1] * 2LL;
	
	LL cur = 0LL;
	bool find = true;

	while(find){
		find = false;
		for(int i = 1; i <= 60; ++i){
			if(V[i].size() == 0)
				continue;

			if(cur & pot[i])
				continue;
			
			find = true;
			res.push_back(V[i].back());
			cur ^= V[i].back();
			V[i].pop_back();
			break;
		}
	}

	if(int(res.size()) < n)
		puts("No");
	else{
		puts("Yes");
		for(LL v: res)
			printf("%lld ", v);

/*		LL sum = 0LL;
		for(LL v: res){
			sum ^= v;
			printf("%lld\n", sum);
		}
*/	}
	
	return 0;
}