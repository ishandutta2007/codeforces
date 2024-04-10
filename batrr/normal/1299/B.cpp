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
 
int n, x[N], y[N], a[N], b[N];
map< pii, int > cnt;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i = 0; i < n; i++){         
		a[i] = (x[(i + 1) % n] - x[i]);
		b[i] = (y[(i + 1) % n] - y[i]);
		cnt[{a[i], b[i]}] = 1;
	}
	for(int i = 0; i < n; i++)
		if(cnt[{-a[i], -b[i]}] == 0){
			printf("No");
			return 0;
		}
	printf("Yes");
}