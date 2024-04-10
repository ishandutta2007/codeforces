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
 
int a[N];
void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	int mn = inf, mx = -inf;
	bool w = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		w |= (a[i] == k);
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if(!w){
		printf("no\n");
		return;
	}
	if(n == 1){
		printf("yes\n");
		return;
	}
	for(int i = 0; i < n; i++){
		if(i + 1 < n){
			if(a[i] >= k && a[i + 1] >= k){
				printf("yes\n");
				return;
			}
		}
		if(i + 2 < n){
			if(a[i] >= k && a[i + 2] >= k){
				printf("yes\n");
				return;
			}
		}
	}
	printf("no\n");
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}