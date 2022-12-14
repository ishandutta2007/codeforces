/**
 *    author:  Atrues
 *    created: 26.01.2019 14:31
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int f[maxn];
vector<int> a;
vector<vector<int> > ans;
int pd[maxn], dp[maxn], tmp[maxn], par[maxn];

int lis(){
	int n = a.size();
	memset(pd, 63, sizeof pd);
	int answer = 0;
	for (int i = 0; i < n; i++){
		int idx = lower_bound(pd, pd + n, a[i]) - pd;
		pd[idx] = a[i], tmp[idx] = i;
		dp[i] = idx + 1;
		answer = max(answer, dp[i]);
		if (idx)
			par[i] = tmp[idx - 1];
		else
			par[i] = -1;
	}
	return answer;
}

bool mark[maxn];

void vitex_lis(){
	int n = a.size();
	int idx = max_element(dp, dp + n) - dp;
	vector<int> lis;
	while (idx != -1){
		lis.push_back(a[idx]);
		mark[idx] = 1;
		idx = par[idx];
	}
	vector<int> komaki;
	for (int i = 0; i < n; i++){
		if (mark[i]){
			mark[i] = 0;
			continue;
		}
		komaki.push_back(a[i]);
	}
	a = komaki;
	reverse(lis.begin(), lis.end());
	ans.push_back(lis);
}

void vitex_lds(){
	int n = a.size();
	int idx = *max_element(dp, dp + n);
	int untilnow = ans.size();
	ans.resize(untilnow + idx);
	for (int i = 0; i < n; i++)
		ans[untilnow + dp[i] - 1].push_back(a[i]);
	a.clear();
}

int main(){
	for (int i = 1; i * (i + 1) / 2 <= int(1e5); i++)
		for (int j = i * (i + 1) / 2 + 1; j < min((i + 2) * (i + 1) / 2, int(1e5)); j++)
			f[j] = i;
	int tc;
	scanf("%d", &tc);
	while (tc --){
		ans.clear();
		int n;	
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		while (lis() > f[a.size()] and !a.empty()){
			vitex_lis();
		}
		if (!a.empty())
			vitex_lds();
		printf("%d\n", int(ans.size()));
		for (auto vec : ans){
			printf("%d ", int(vec.size()));
			for (auto it : vec)
				printf("%d ", it);
			printf("\n");
		}
	}
}