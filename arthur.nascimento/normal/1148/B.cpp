#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200200
#define inf (1e15)
int a[maxn];
int b[maxn];

int main(){

	int n,m,ta,tb,k;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	
	for(int i=0;i<m;i++)
		scanf("%d",b+i);
	
	int p2 = 0;
	
	ll ans = -1;
	
	if(k >= n || k >= m) ans = inf;
	
	for(int i=0;i<n;i++){
	
		if(i > k) continue;
		
		while(p2 < m && b[p2] < a[i] + ta)
			p2++;
			
		int can = k-i;
			
		if(p2+can >= m) ans = inf;
		
		ans = max(ans, (ll) b[p2+can] + tb);
		
	
	}
	
	if(ans == inf) ans = -1;
	printf("%lld\n",ans);

}