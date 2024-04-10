#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1000 * 1000 + 7;

int n;
int perm[N];
vector <int> T[N];

int main(){
	scanf("%d", &n);
	LL bestAns, curAns = 0LL;
	int diff = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &perm[i]);
		if(perm[i] <= i){
			T[n + perm[i] - i].push_back(i);
			++diff;
		}
		else{
			--diff;
			T[perm[i] - i].push_back(i);
		}

		curAns += abs(perm[i] - i);
	}
	
	int corTime = 0;
	bestAns = curAns;
	
	for(int i = 1; i < n; ++i){
		curAns += (diff - 1);
		for(int v: T[i])
			diff += 2;
		diff -= 2;
		curAns += 2 * perm[n - i + 1] - 1 - n;
		
		if(curAns < bestAns){
			bestAns = curAns;
			corTime = i;
		}
	}
	
	printf("%lld %d\n", bestAns, corTime);
	return 0;
}