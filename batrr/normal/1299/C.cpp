#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k;
ll a[N], b[N];
void add(ll x, ll cnt){
	if(k && a[k - 1] * cnt >= x * b[k - 1]){
		k--;
		add(x + a[k], cnt + b[k]);
	}else{
		a[k] = x;
		b[k] = cnt;
		k++;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		ll x;
		scanf("%lld", &x);
		add(x, 1);
	}
	for(int i = 0; i < k; i++)
		for(int j = 0; j < b[i]; j++)
			printf("%.15f\n", 1.0 * a[i] / b[i]);
}