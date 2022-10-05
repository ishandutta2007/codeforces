#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, a[N], dp[N][5], pr[N][5];
bool good(int a1, int a2, int b1, int b2){
	if(a1 < a2)
		return b1 < b2;
	if(a1 > a2)
		return b1 > b2;
	if(a1 == a2)
		return b1 != b2;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < 5; i++)
		dp[0][i] = 1;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < 5; j++)
			for(int q = 0; q < 5; q++)
				if(good(a[i - 1], a[i], j, q) && dp[i - 1][j])
					dp[i][q] = 1, pr[i][q] = j;
	int cur = -1;
	for(int i = 0; i < 5; i++)
		if(dp[n - 1][i])
			cur = i;
	if(cur == -1){
		printf("-1");
		return 0;
	}
	vector< int > ans;
	for(int i = n - 1; i >= 0; i--){
		ans.pb(cur);
		cur = pr[i][cur];
	}
	for(int i = n - 1; i >= 0; i--)
		printf("%d ", ans[i] + 1);
	
	return 0;
}