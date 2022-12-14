#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn];
int mark[maxn];

void solve(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m = 3 * n;
	int now = 1;
	while (m --){
		mark[now] ++;
		now = now - a[now];
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (mark[i] > 1)
			ans.push_back(i);
	int sz = ans.size();
	printf("%d\n", sz);
	for (auto it : ans)
		printf("%d ", it);
	printf("\n");
	for (int i = 1; i <= n; i++)
		mark[i] = 0;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc --){
		solve();
	}
}