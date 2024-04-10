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

int n, res = 1;
vector <int> pt;

int main(){
	scanf("%d", &n); int t = n;
	for(int i = 2; i <= n; ++i){
		if(t%i == 0){
			int cnt = 0;
			while(t%i == 0){
				t /= i;
				++cnt;
			}
			
			res *= i;
			pt.push_back(cnt);
		}
	}
	
	if(n == 1){
		puts("1 0");
		return 0;
	}
	
	printf("%d ", res);
	sort(pt.begin(), pt.end());
	
	bool paid = false;		
	res = 0;

	while(pt.back() > 1){
		bool np = false;
		for(int v: pt)
			np |= v & 1;
		
		if(!paid && np){
			paid = true;
			++res;
		}
		
		for(int &v: pt)
			v = (v + 1) / 2;
		++res;
	}
	
	printf("%d\n", res);
	return 0;
}