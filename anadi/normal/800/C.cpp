#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int inf = 1e9 + 7;

int n, m;
int p[N];
int dp[N];
bool forb[N];
vector <int> V[N];

LL nwd(LL a, LL b){
	return b == 0LL ? a : nwd(b, a%b);
}

PLL Ext_Gcd(LL a, LL b){
	if(b == 0)
		return {1, 0};
	PLL res = Ext_Gcd(b, a%b);
	return {res.nd, res.st - (a / b) * res.nd};
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		forb[a] = true;
	}
	
	for(int i = 0; i < m; ++i)
		if(!forb[i])
			V[nwd(i, m)].push_back(i);

	for(int i = m; i >= 1; --i){
		p[i] = m + 1;
		for(int j = 2 * i; j <= m; j += i)
			if(dp[j] > dp[p[i]])
				p[i] = j;
		dp[i] = dp[p[i]] + V[i].size();
	}

	int i = 1;
	int now = 1;
	int last = 1;
	vector <int> res;
	while(i <= m){
		now = i;
		
		for(int v: V[i]){
			PLL ret = Ext_Gcd(last, m);
			ret.first %= m;
			ret.first *= 1LL * v / nwd(last, m);
			ret.first %= m;
			ret.first += m;
			ret.first %= m;
			last = v;
			res.push_back(ret.first);
		}
		
		i = p[i];
	}
	
	printf("%d\n", res.size());
	for(int v: res)
		printf("%d ", v);
	return 0;
}