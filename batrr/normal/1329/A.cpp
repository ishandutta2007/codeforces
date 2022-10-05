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
 
int n, m, a[N], b[N];
int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = n; i >= 1; i--){
		b[i] = max(a[i], b[i + 1] + 1);
	}
	if(b[1] > m){
		printf("-1");
		return 0;
	}
	b[1] = m;
	for(int i = 2; i <= n; i++)
		b[i] = max(b[i], b[i - 1] - a[i - 1]);		
	if(b[n] - a[n] > 0){
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", b[i] - a[i] + 1);
}