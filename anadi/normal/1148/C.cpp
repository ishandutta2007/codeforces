#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
int place[N];
vector <PII> ans;

void zamien(int a, int b){
	ans.push_back({a, b});
	swap(in[a], in[b]);

	place[in[a]] = a;
	place[in[b]] = b;
}

bool poss(int a, int b){
	return 2 * abs(a - b) >= n;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		place[in[i]] = i;
	}
	
	for(int i = 1; i <= n; ++i){
		if(place[i] == i)
			continue;
		
		if(poss(place[i], i)){
			zamien(place[i], i);
			continue;
		}
		
		if(poss(place[i], n)){
			zamien(place[i], n);
			zamien(place[i], i);
			continue;
		}
		
		zamien(place[i], 1);
		if(poss(place[i], i))
			zamien(place[i], i);
		else{
			zamien(place[i], n);
			zamien(place[i], i);
		}
		
		zamien(place[1], 1);
	}
	
	for(int i = 1; i <= n; ++i)
		assert(place[i] == i);
	
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d %d\n", v.st, v.nd);
	return 0;
}