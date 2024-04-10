#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1.5e7 + 123, mod = (int)1e9 + 7, inf = (int)1e9;

int n, a[N], g, cnt[N], ld[N], ans;
int main(){    
	for(int i = 2; i < N; i+=2)
		ld[i] = 2;
	for(int i = 3; i < N; i+=2){
		if(ld[i] == 0){
			ld[i] = i;
			if(1ll*i*i < N)
            	for(int j = i*i; j < N; j += i + i)
					ld[j] = i;
		}
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(i == 0)
			g = a[i];
		else
        	g = __gcd(g, a[i]);
	}
	for(int i = 0; i < n; i++)
		a[i] /= g;
	sort(a, a + n);
	if(a[0] == 1 && a[n - 1] == 1){
		printf("-1");
		return 0;
	}
	for(int i = 0; i < n; i++){
		int x = a[i];
		while(x!=1){
			int y = ld[x];
			cnt[y]++;
			while(x % y == 0)
				x /= y;
		}
	}
	ans = inf;
	for(int i = 0; i < N; i++)
		ans = min(ans, n - cnt[i]);
	printf("%d",ans);
	return 0;
}