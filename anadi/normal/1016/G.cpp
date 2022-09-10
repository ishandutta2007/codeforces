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
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL X, Y;
int sum[N];
vector <LL> A, B;

LL nwd(LL a, LL b){
	return b == 0 ? a : nwd(b, a%b);
}

LL ask(LL a){
	LL ret = 1LL;
	while(ret * a < Y){
		ret = Y / a;
		a /= nwd(ret, a);
	}
	
	if(ret%X != 0)
		ret = ret * (X / nwd(ret, X));
	return ret;
}

vector <LL> get(LL a){
	vector <LL> ret;
	for(int i = 2; i < (int)3e6; ++i){
		if(a%i != 0)
			continue;
		
		ret.push_back(i);
		while(a%i == 0)
			a /= i;
	}
	
	if(a > 1){
		for(auto v: B)
			if(nwd(a, v) > 1 && nwd(a, v) < a){
				ret.push_back(nwd(a, v));
				a /= nwd(a, v);
				break;
			}

		for(auto v: A)
			if(nwd(a, v) > 1 && nwd(a, v) < a){
				ret.push_back(nwd(a, v));
				a /= nwd(a, v);
				break;
			}
		
		if(a > 1)
			ret.push_back(a);
	}
	
	vector <LL> res;
	sort(ret.begin(), ret.end());
	
	for(auto v: ret)
		if(res.size() == 0 || res.back() != v)
			res.push_back(v);
	return res;
}

int main(){
	scanf("%d %I64d %I64d", &n, &X, &Y);
	if(Y%X != 0){
		puts("0");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		LL in;
		scanf("%I64d", &in);
		
		if(in%X == 0)
			A.push_back(nwd(in / X, Y));
		
		if(Y%in == 0){
			LL d = ask(in);
			B.push_back(d / X);
		}
	}
	
	vector <LL> primes = get(Y);
	for(auto v: A){
		int mask = 0;
		for(int j = 0; j < (int)primes.size(); ++j)
			if(v%primes[j] == 0)
				mask += 1 << j;
		sum[mask]++;
	}
	
	int m = primes.size();
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < (1 << m); ++j)
			if(j & (1 << i))
				sum[j] += sum[j ^ (1 << i)];
	
	LL res = 0LL;
	m = 1 << m;

	for(auto v: B){
		int mask = 0;
		for(int j = 0; j < (int)primes.size(); ++j)
			if(v%primes[j] == 0)
				mask += 1 << j;
		res += sum[(m - 1) ^ mask];
	}
	
	printf("%I64d\n", res);
	return 0;
}