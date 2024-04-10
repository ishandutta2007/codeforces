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

int n, a[N];
int x, xx, y, yy;
ll k, pre[N];
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		reverse(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + a[i] / 100;
		scanf("%d%d", &x, &xx);	
		scanf("%d%d", &y, &yy);	
		scanf("%lld", &k);
		
		if(x < y){
			swap(x, y);
			swap(xx, yy);
		}
		
		int ANS = -1;


		int cx = 0, cy = 0, cxy = 0;

		for(int i = 1; i <= n; i++){
			if(i % xx == 0 && i % yy == 0)
				cxy++;
			else if(i % xx == 0)
				cx++;
			else if(i % yy == 0)
				cy++;
			ll cur = pre[cxy] * (x + y) + (pre[cxy + cx] - pre[cxy]) * x + (pre[cxy + cx + cy] - pre[cxy + cx]) * y;
			if(cur >= k){
				ANS = i;
				break;
			}
		}                   
		printf("%d\n", ANS);
	}
	return 0;
}