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
 
ll n, a[N], b[N];
int main()
{
	scanf("%lld", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
    ll mx = 0;
    for(int i = 0; i < n; i++){
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);		
	}
	for(int i = 0; i < n; i++)
		printf("%lld ", a[i]);
}