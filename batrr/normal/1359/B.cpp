#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;


int n, m, x, y, ans;
char s[N]; 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &x, &y);
		ans = 0;
		y = min(y, x + x);
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			for(int j = 0; j < m; j++){
				if(s[j] == '*')
					continue;
				if(j + 1 < m && s[j + 1] == '.')
					j++, ans += y;
				else
					ans += x;
			}
		}
		printf("%d\n", ans);
	}
}