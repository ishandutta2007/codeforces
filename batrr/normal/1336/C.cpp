#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 3100, mod = 998244353;
 
char s[N], t[N];
int n, m, dp[N][N], ans;
void add(int &a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
}
int main()
{                  
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			if(j + i >= m || s[i] == t[j + i])
				add(dp[i + 1][j], dp[i][j]);				
			if(j > 0 && (j - 1 >= m || s[i] == t[j - 1])) 
				add(dp[i + 1][j - 1], dp[i][j]);				
		}	
	}                             
	for(int i = m; i <= n; i++)
		add(ans, dp[i][0]);
	printf("%d", ans);
}