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
 
int n, m, a[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		a[i] = -1;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(a[x % m] != -1){
			printf("0");
			return 0;
		}
		a[x % m] = x;
	}
	ll ans = 1;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < i; j++)
			if(a[i] != -1 && a[j] != -1)
            	ans = ans * abs(a[i] - a[j]) % m;
	printf("%lld", ans);	
}