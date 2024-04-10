#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>

const int mxn = 2e5 + 9LL;
const LL MX = 1e9 + 7LL;

LL n, k;
LL sil[mxn];
priority_queue <PII> Q;

LL szybkie(LL a, LL b){
	if(b == 0)
		return 1LL;
	LL x = szybkie(a, b / 2LL);
	if(b & 1)
		return (((x * x)%MX) * a)%MX;
	return (x * x)%MX;
}

LL RevMod(LL a){
	return szybkie(a, MX - 2);
}

LL newton(LL a, LL b){
	LL res = sil[a];
	res *= RevMod(sil[b]);
	res %= MX;
	res *= RevMod(sil[a - b]);
	res %= MX;
	return res;
}

int main(){
	scanf("%I64d %I64d", &n, &k);
	sil[0] = 1LL;
	for(LL i = 1LL; i <= n; ++i)
		sil[i] = (sil[i - 1] * i)%MX;
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		++b;
		Q.push(mp(-a, 1));
		Q.push(mp(-b, -1));
	}
	LL result = 0LL;
	
	int last = 0;
	int ile = 0;
	while(!Q.empty()){
		PII K = Q.top();
		Q.pop();
		K.st *= -1;
		LL l = K.st - last;
		
		if(ile >= k)
			result += newton(ile, k) * l;
		ile += K.nd;
		last = K.st;
		result %= MX;
	}
	
	printf("%I64d\n", result);
	return 0;
}