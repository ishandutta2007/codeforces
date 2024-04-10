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
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a = 0, b = -inf;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			a = max(a, b - x);
			b = max(b, x);
		}
		int ans = 0;
		while(a)
			a /= 2, ans++;
		printf("%d\n", ans);
	}	
}