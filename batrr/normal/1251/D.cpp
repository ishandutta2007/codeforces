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

int n;
pii a[N];
ll s;
int get(int x){
	ll ss = 0;
	for(int i = 0; i < n; i++)
		ss += a[i].f;
	int res = 0;
	for(int i = 0; i < n; i++){
		if(x <= a[i].f){
			res++;
			continue;
		}
		if(x <= a[i].s && ss + x - a[i].f <= s)
			res++, ss += x - a[i].f;
	}	
	return res;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &s);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &a[i].f, &a[i].s);
		sort(a, a + n);
		reverse(a, a + n);
		int l = 0, r = 1e9 + 100;
		while(l <= r){
			int m = (l + r) >> 1;
			if(get(m) > n / 2)
				l = m + 1;
			else
				r = m - 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}