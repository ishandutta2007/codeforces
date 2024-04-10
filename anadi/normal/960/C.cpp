#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int x, d;
vector <LL> res;

int main(){
	scanf("%d %d", &x, &d); LL last = 1, sum = 0;
	for(int i = 1; i < 30; ++i)
		if(x & (1 << i)){
			for(int j = 0; j < i; ++j)
				res.push_back(last);

			last += d;
			sum += (1 << i) - 1;
		}
	
	while(sum < x){
		res.push_back(last), last += d;
		++sum;
	}
	
	printf("%d\n", (int)res.size());
	for(LL v: res)
		printf("%lld ", v);
	return 0;
}