#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define mp make_pair
#define PII pair <int, int>
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1e5 + 7;

int n;
int t[N];

int BS(int a){
	int pocz = 1, kon = n;
	if(t[kon] <= a)
		return n;
	if(t[pocz] > a)
		return 0;
	
	while(pocz < kon){
		int mid = (pocz + kon) / 2;
		if(t[mid] <= a)
			pocz = mid + 1;
		else
			kon = mid;
	}
	
	return pocz - 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	sort(t + 1, t + n + 1);
	
	int q;
	scanf("%d", &q);
	while(q--){
		int a;
		scanf("%d", &a);
		printf("%d\n", BS(a));
	}

	return 0;
}