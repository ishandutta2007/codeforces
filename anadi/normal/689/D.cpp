#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>

const int mxn = 2e5 + 7;
const int LOGN = 19;

int n;
int RMQ[2][LOGN][mxn];
int val[mxn];

int mn(int a, int b){
	int l = val[b - a + 1];
	return min(RMQ[1][l][a], RMQ[1][l][b - (1 << l) + 1]);
}

int mx(int a, int b){
	int l = val[b - a + 1];
	return max(RMQ[0][l][a], RMQ[0][l][b - (1 << l) + 1]);
}

int BS(int a){
	int pocz = a, kon = n;
	while(pocz < kon){
		int mid = (pocz + kon + 1) / 2;
		if(mn(a, mid) <= mx(a, mid))
			kon = mid - 1;
		else
			pocz = mid;
	}
	
	if(mn(a, pocz) == mx(a, pocz))
		--pocz;
	return pocz;
}

int BS2(int a){
	int pocz = a, kon = n;
	while(pocz < kon){
		int mid = (pocz + kon + 1) / 2;
		if(mn(a, mid) >= mx(a, mid))
			pocz = mid;
		else
			kon = mid - 1;
	}
	
	return pocz;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &RMQ[0][0][i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &RMQ[1][0][i]);
	
	int x = 0;
	for(int i = 1; i <= n; ++i){
		if(i >= (1 << (x + 1)))
			++x;
		val[i] = x;
	}
	
	for(int l = 1; l < LOGN; ++l)
		for(int i = 1; i <= n; ++i)
			RMQ[0][l][i] = max(RMQ[0][l - 1][i + (1 << (l - 1))], RMQ[0][l - 1][i]);
	
	for(int l = 1; l < LOGN; ++l)
		for(int i = 1; i <= n; ++i)
			RMQ[1][l][i] = min(RMQ[1][l - 1][i], RMQ[1][l - 1][i + (1 << (l - 1))]);
	
	LL result = 0LL;
	for(int i = 1; i <= n; ++i)
		result += (LL)max(0, BS2(i) - BS(i));
	printf("%I64d\n", result);
	return 0;
}