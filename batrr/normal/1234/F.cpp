#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7, LOG = 20;
const ll INF = 1e18;

int n, a[N], dp[1 << LOG], ans;
char s[N];
void add(int x, int val){
	if(dp[x] >= val)
		return;
	dp[x] = val;
	for(int i = 0; i < LOG; i++)
		if((x >> i) & 1)
			add(x ^ (1 << i), val);
}
int main()
{
	scanf("%s", &s);
	n = strlen(s);
	for(int i = 0; i < n; i++)
		a[i] = s[i] - 'a';

	for(int i = 0; i < n; i++){
		int cur;
		cur = 0;
		for(int j = i; j < n; j++){
			if((cur >> a[j]) & 1)
				break;
			cur |= (1 << a[j]);						
			ans = max(ans, dp[cur] + j - i + 1);	
		}
		cur = 0;
		for(int j = i; j >= 0; j--){
			if((cur >> a[j]) & 1)
				break;
			cur |= (1 << a[j]);						
			add(((1 << LOG) - 1) ^ cur, i - j + 1);
		}
	}
	printf("%d", ans);
	return 0;
}