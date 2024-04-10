#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int in[N];
vector <int> cows[N];

int Left[N], Right[N];
int take[N], poss[N], New[N];

void update(int t){
	int canTake = 0;
	if(cows[t][0] <= Left[t] || cows[t][0] <= Right[t])
		canTake = 1;
	
	if(cows[t].size() >= 2){
		int mn = min(Left[t], Right[t]);
		int mx = max(Left[t], Right[t]);
		
		if(cows[t][0] <= mn && cows[t][1] <= mx)
			canTake = 2;
	}
	
	if(canTake == 0){
		if(take[t] == 0)
			return;

		take[t] = 0, poss[t] = 1, New[t] = 1;
		return;
	}
	
	if(canTake == 1){
		int xd = 0;
		for(auto v: cows[t]){
			if(v <= Left[t])
				++xd;
			if(v <= Right[t])
				++xd;
		}
		
		if(take[t] != canTake){
			take[t] = 1;
			poss[t] = New[t] = xd;
		}
		else{
			poss[t] = xd;
			for(auto v: cows[t])
				if(v == Left[t])
					New[t] = 1;
		}
		
		return;
	}
	
	int prawo = 0;
	poss[t] = 0;

	for(auto v: cows[t])
		if(v <= Right[t])
			++prawo;
	
	for(int i = 0; i < (int)cows[t].size(); ++i)
		if(cows[t][i] <= Left[t]){
			poss[t] += prawo;
			if(cows[t][i] <= Right[t])
				--poss[t];
		}
	
	if(canTake != take[t]){
		take[t] = 2;
		New[t] = poss[t];
		return;
	}
	
	for(int i = 0; i < (int)cows[t].size(); ++i)
		if(cows[t][i] == Left[t]){
			New[t] = prawo;
			if(cows[t][i] <= Right[t])
				--New[t];
		}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= m; ++i){
		int f, h;
		scanf("%d %d", &f, &h);
		cows[f].push_back(h);
	}
	
	for(int i = 1; i <= n; ++i)
		sort(cows[i].begin(), cows[i].end());

	for(int i = 1; i <= n; ++i){
		Right[in[i]]++;
		poss[i] = 1;
	}
	
	int ans = 0, ans2 = 1;
	for(int i = 1; i <= n; ++i){
		if(cows[i].size() == 0)
			continue;

		update(i);
		ans += take[i];
		ans2 = (1LL * ans2 * poss[i]) % MX;
	}

	for(int i = 1; i <= n; ++i){
		Right[in[i]]--;
		Left[in[i]]++;
		
		for(int j = 1; j <= n; ++j)
			New[j] = 0;

		if(cows[in[i]].size())
			update(in[i]);
		
		int now = 0;
		for(int j = 1; j <= n; ++j)
			now += take[j];
		
		if(now < ans)
			continue;
		
		if(now > ans){
			ans = now;
			ans2 = 0;
		}
		
		int tmp1 = 1, tmp2 = 1;
		for(int j = 1; j <= n; ++j){
			tmp1 = (1LL * tmp1 * poss[j]) % MX;
			tmp2 = (1LL * tmp2 * (poss[j] - New[j])) % MX;
		}
		
		ans2 = (1LL * ans2 + tmp1 + MX - tmp2) % MX;
	}
	
	printf("%d %d\n", ans, ans2);
	return 0;
}