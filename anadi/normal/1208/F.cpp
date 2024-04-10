#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1 << 21;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int First[N];
PII last[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < N; ++i){
		First[i] = n + 1;
		last[i] = {0, 0};
	}

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);

		if(First[x] == n + 1)
			First[x] = i;
		
		last[x].nd = last[x].st;
		last[x].st = i;
	}
	
	for(int i = 0; i < 21; ++i)
		for(int j = 0; j < N; ++j)
			if(!(j & (1 << i))){
				int id = j ^ (1 << i);
//				printf("UPDATE %d %d :: %d %d\n", j, id, First[j], First[id]);
				First[j] = min(First[j], First[id]);
	
				if(last[id].st > last[j].st){
					last[j].nd = max(last[j].st, last[id].nd);
					last[j].st = last[id].st;
				}
				else
					last[j].nd = max(last[id].st, last[j].nd);
			}
	
//	for(int i = 0; i < 10; ++i)
//		printf("%d -> %d %d %d\n", i, First[i], last[i].st, last[i].nd);
	
	int res = 0;
	for(int i = 0; i < N; ++i){
		if(last[i].nd <= 1)
			continue;
		
		int ans = i; int best = 0;
		for(int j = 20; j >= 0; --j){
			if(ans & (1 << j))
				continue;
			
			if(First[best | (1 << j)] < last[i].nd)
				best |= 1 << j;
		}
		
		res = max(res, ans | best);
	}
	
	printf("%d\n", res);
	return 0;
}